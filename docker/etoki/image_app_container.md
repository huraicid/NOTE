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


## 実行コマンド
```bash
docker container run
 --name app \
 --rm \
 --detach \
 --publish 8000:8000 \
 --mount type=bind,source="$(pwd)"/src,target=/my-work \
 --network work-network \
 work-app:0.1.0 \
 /usr/local/bin/php --server 0.0.0.0:8000 --docroot /my-work
 ```