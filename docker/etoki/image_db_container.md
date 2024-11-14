# DBコンテナ
- [ ] イメージはmysql:8.2.0を使用
- [ ] `--env`で`MYSQL_ROOT_PASSWORD=secret`を指定
- [ ] `--env`で`MYSQL_USER=app`を指定
- [ ] `--env`で`MYSQL_PASSWORD=pass1234`を指定
- [ ] `--env`で`MYSQL_DATABASE~=sample`を指定
- [ ] `--env`で`TZ=Asia/Tokyo`を指定
- [ ] `--publish`で`3306:3306`を指定


## ボリューム

```bash
docker volume create --name work-db-volume
```

|key|value|補足|
|---|---|---|
|type|volume|ボリュームマウントを使用|
|source|work-db-volume|マウント元。DBコンテナ用のボリューム名|
|destination|/var/lob/mysql|マウント先。調べたデータの保存先|


## バインドマウント

|key|value|補足|
|---|---|---|
|type|bind|バインドマウントを使用|
|source|"$(pwd)"/docker/db/init|マウント元。`src`ディレクトリのフルパス|
|destination|/docker-entrypoint-initdb.d|マウント先。https://hub.docker.com/_/mysql の#Initializing a fresh instanceを参照|


## ネットワーク
`--nerwork work-network`


## 実行コマンド
### ボリューム作成
```bash
docker volume create --name work-db-volume
```

### コンテナ作成・実行
```bash
docker container run \
--name db \
--rm \
--detach \
--env MYSQL_ROOT_PASSWORD=secret \
--env MYSQL_USER=app \
--env MYSQL_PASSWORD=pass1234 \
--env MYSQL_DATABASE=sample \
--env TZ=Asia/Tokyo \
--publish 3306:3306 \
--mount \
type=volume,source=work-db-volume,target=/var/lib/mysql \
--mount \
type=bind,source="$(pwd)"/docker/db/init,target=/docker-entrypoint-initdb.d \
--network work-network \
mysql:8.2.0
```