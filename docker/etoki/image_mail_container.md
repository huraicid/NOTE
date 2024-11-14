# Mailコンテナ
- [ ] イメージは`axllent/mailpit:v1.10.1`を使用
- [ ] Appコンテナから1025版ポートを使用してメールを送信
- [ ] `--publish`で`8025:8025`を指定
- [ ] `--env`で`TZ=Asia/Tokyo`を指定
- [ ] `--env`で`MP_DATA_FILE=/data/mailpit.db`を指定


## ボリューム

```bash
docker volume create --name work-mail-volume
```

|key|value|補足|
|---|---|---|
|type|volume|ボリュームマウントを使用|
|source|work-mail-volume|マウント元。Mailコンテナ用のボリューム名|
|destination|/data|マウント先。調べたデータの保存先|


## バインドマウント
使用しない。


## ネットワーク
`--nerwork work-network`