# Mailコンテナ
- [ ] イメージは`axllent/mailpit:v1.10.1`を使用
- [ ] Appコンテナから1025版ポートを使用してメールを送信
- [ ] `--publish`で`8025:8025`を指定
- [ ] `--env`で`TZ=Asia/Tokyo`を指定
- [ ] `--env`で`MP_DATA_FILE=/data/mailpit.db`を指定