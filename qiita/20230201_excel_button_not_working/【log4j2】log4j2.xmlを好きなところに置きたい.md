# 動機
log4j2で使うlog4j2.xmlをsrc直下に置くのはダサいと思ったため、別の場所に置きたかった。
しかし、その方法がググってもちゃんとは出てなかったため、備忘録として残しておく。

# 環境
- Windows10
- eclipse IDE
  - Version: 2022-09 (4.25.0)
  - Build id: 20220908-1902
- JRE: JavaSE-1.8

# 結論
`Logger`クラスを作る前に以下のコードを使ってlog4j2.xmlを読み込めばよい：

```java
System.setProperty("log4j.configurationFile", "<ファイルパス>");
```


# 導入
通常の場合、log4j2 + SLF4Jでログ出力をする時、`/src`直下にlog4j2.xmlを配置する必要がある：
```
src/
  - log4j2WithSlf4j
    - Main.java
  - log4j2.xml
```

ただし、以下の必要なライブラリはビルドパスに通しておく（古かったら適宜差し替えておいてください）。
- log4j-api-2.19.0.jar
- log4j-core-2.19.0.jar
- log4j-slf4j-impl-2.19.0.jar
- slf4j-api-1.7.25.jar

Main.javaとlog4j2.xmlはシンプルに書いておく。
ログファイルに出力することは考えずに、コンソールに出るようにしておく。

```Main.java
package log4j2WithSlf4j;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Main {
	public static void main(String[] args) {
		Logger logger = LoggerFactory.getLogger(Main.class);
	    logger.info("Hello World !!");
	    
	    System.out.println("end");
	}
}
```

```log4j2.xml
<?xml version="1.0" encoding="UTF-8"?>
<Configuration status="WARN" monitorInterval="30">
    <Properties>
        <Property name="LOG_PATTERN">%d{yyyy-MM-dd HH:mm:ss} %-5p %c{1} - %m%n</Property>
    </Properties>
 
    <Appenders>
        <Console name="console" target="SYSTEM_OUT" follow="true">
            <PatternLayout pattern="${LOG_PATTERN}"/>
        </Console>
    </Appenders>
 
    <Loggers>
        <Root level="info">
            <AppenderRef ref="console"/>
        </Root>
    </Loggers>
</Configuration>
```

Javaアプリケーションとして実行すると、以下のような出力が得られる：

```Main.javaの出力結果
2022-12-02 23:35:05 INFO  Main - Hello World !!
end
```


# 本題：log4j2.xmlを読み込むには

以下ではちゃんと読み込まれているか判別できるようにするため、ログ出力をちょっと変える。
~~コンソールちゃんに褒めてほしい人生だった。~~

```log4j2.xml
<?xml version="1.0" encoding="UTF-8"?>
<Configuration status="WARN" monitorInterval="30">
    <Properties>
    	<Property name="CONGRATURATIONS">出力できてるじゃん！すっごーい！！！</Property>
        <Property name="LOG_PATTERN">${CONGRATURATIONS} %d{yyyy-MM-dd HH:mm:ss} %-5p %c{1} - %m%n</Property>
    </Properties>
 
    <Appenders>
        <Console name="console" target="SYSTEM_OUT" follow="true">
            <PatternLayout pattern="${LOG_PATTERN}"/>
        </Console>
    </Appenders>
 
    <Loggers>
        <Root level="debug">
            <AppenderRef ref="console"/>
        </Root>
    </Loggers>
</Configuration>
```

例えば下のようにlog4j2.xmlを配置したとする：

```
src/
  - log4j2WithSlf4j
    - Main.java
    - log4j2.xml
```

この時、Main.javaでは1行追加すればOK。

```diff_java
package log4j2WithSlf4j;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Main {
	public static void main(String[] args) {
+		System.setProperty("log4j.configurationFile", "log4j2WithSlf4j/log4j2.xml");
	
		Logger logger = LoggerFactory.getLogger(Main.class);
	    logger.info("Hello World !!");
	    
	    System.out.println("end");
	}
}
```

```Main.javaの出力結果
出力できてるじゃん！すっごーい！！！ 2022-12-02 23:41:04 INFO  Main - Hello World !!
end
```

**やったぜ**。

ちなみに`src/`下じゃない別フォルダでもいけるらしい。

### 例：src外のconfigフォルダの場合

下のような配置であったとする。

```
src/
  - log4j2WithSlf4j
    - Main.java
config/
  - log4j2.xml
```

この時も同じように1行追加すればよい。

```diff_java
package log4j2WithSlf4j;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Main {
	public static void main(String[] args) {
+		System.setProperty("log4j.configurationFile", "config/log4j2.xml");
	
		Logger logger = LoggerFactory.getLogger(Main.class);
	    logger.info("Hello World !!");
	    
	    System.out.println("end");
	}
}
```

```Main.javaの出力結果
出力できてるじゃん！すっごーい！！！ 2022-12-02 23:51:00 INFO  Main - Hello World !!
end
```

※`/src`基準でファイルパスを書くとうまくいきませんでした。どなたかご教示願います。。


# 後書き
これを機に`System.*`について勉強しようと思いました。本来ならあまり使うべきものではなさそうだけど。


# 参考
- 技術空間様：[log4j/log4j設定ファイルのファイル名や読み込み先を変える方法](http://teqspaces.com/log4j/2)
  - 何か方法はないだろうかと彷徨ってたら一筋の光が。log4j向けだったので結局使えませんでしたが、調べる動機になりました。
- stack overflow：[ERROR StatusLogger Reconfiguration failed: No configuration found for '73d16e93' at 'null' in 'null'](https://stackoverflow.com/questions/66545546/error-statuslogger-reconfiguration-failed-no-configuration-found-for-73d16e93)
  - 質問者、回答者諸兄に最上級の感謝を。
