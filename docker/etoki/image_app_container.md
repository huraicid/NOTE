# Appサーバ
- [ ] イメージは`work-app:0.1.0`を使用
- [ ] `--publish`で`8000:8000`を指定


## ボリューム
使用しない。


## バインドマウント

|key|value|補足|
|---|---|---|
|type|bind|バインドマウントを使用|
|source|"$(pwd)"/src|マウント元。`src`ディレクトリのフルパス|
|destination|/my-work|マウント先。`--docroot`で定めた`/my-work`|


## ネットワーク
`--nerwork work-network`