### 普通の順次処理
```js
function process1() {
    console.log("1番目");
}

function process2() {
   console.log("2番目");
}

function process3() {
    console.log("3番目");
}

process1();
process2();
process3();
```

出力：
```
1番目
2番目
3番目
```


### 非同期処理が間に入る時、順番が正しくならない
#### 1. setTimeoutの例（順番が正しくならない場合）
この例はよく使われる：

```js
function process1() {
    console.log("1番目");
}

function process2() {
    // 1秒後に実行する処理
 setTimeout(() => {
   console.log("2番目(1秒後に実行)");
 }, 1000);
}

function process3() {
    console.log("3番目");
}

process1();
process2();
process3();
```

出力：
```js
1番目
3番目
2番目(1秒後に実行)
```

ので特にコメントはしない。


#### 2. 単純に時間がかかる処理では順番が正しく実行される

最初に参考してた、『qiita:【ES6】 JavaScript初心者でもわかるPromise講座』[^es6_promise_ko-za]で以下のような記述があるが、これは正しくない。

> JavaScriptは非同期言語であるため、一つ前の実行に時間がかかった場合、実行完了をまたずに次の処理が行われてしまいます。

例えば以下の処理のように`process2()`が重い処理を考える：

```js
function process1() {
    console.log("1番目");
}

function process2() {
    let milliSeconds = 0;
    // 1秒後に実行する処理
    for(let i = 0; i < 100000000; i++) {
        milliSeconds = milliSeconds + 1;
    }
   console.log("2番目（1億ループ後に実行)");
}

function process3() {
    console.log("3番目");
}

process1();
process2();
process3();
```

出力：
```
1番目
2番目（1億ループ後に実行)
3番目
```

`process2()`のループ数を増やしても変わらなかった。正しくは「setTimeoutのような非同期処理をする関数を使用している」場合は、同期処理の後にその関数が実行される、という理解が正しそうだ[^js_atomawashininaru?]。

ただ、ここら辺の話はJavascriptのイベントループを理解する必要がありそうだ（qiita:JavaScriptでは「時間のかかる処理」は後回しになる？[のコメントより](https://qiita.com/monji586/items/aa4b4f8f873412ccfd50)）。

イベントスレッドを視覚的にしたものは[JavaScript イベントループの仕組みをGIFアニメで分かりやすく解説](https://coliss.com/articles/build-websites/operation/javascript/javascript-visualized-event-loop.html)がわかりやすそう。


### 後で読む
- qiita:JavaScriptでは「時間のかかる処理」は後回しになる？のコメント：https://qiita.com/monji586/items/aa4b4f8f873412ccfd50
- JavaScript イベントループの仕組みをGIFアニメで分かりやすく解説：https://coliss.com/articles/build-websites/operation/javascript/javascript-visualized-event-loop.html


### 脚注
[^es6_promise_ko-za]: https://qiita.com/cheez921/items/41b744e4e002b966391a
[^js_atomawashininaru?]: 参考：『qiita:JavaScriptでは「時間のかかる処理」は後回しになる？』, https://qiita.com/monji586/items/aa4b4f8f873412ccfd50
