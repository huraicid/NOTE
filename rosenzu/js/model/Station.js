class Station {
    // 駅名
    name = "";
    // x座標
    x = 0;
    // y座標
    y = 0;
    // 次の停車駅一覧
    nextStations = [];

    constructor(name, x, y, nextStations) {
        this.x = x;
        this.y = y;
        this.nextStations = nextStations;
    }

    // 駅のオブジェクトをcanvas上に描画する
    draw(context) {
        // const
        // オブジェクトの大きさ
        const STATION_RADIUS = 5;
        // 塗りつぶしの色
        const FILL_COLOR = "white";
        // 枠線の色
        const LINE_COLOR = "black";

        context.beginPath();
        context.arc(this.x, this.y, 5, 0, Math.PI * 2, true);
        context.fillStyle = FILL_COLOR;
        context.fill();
        context.strokeStyle = LINE_COLOR;
        context.lineWidth = 1;
        context.stroke();
    }

    // 路線をcanvas上に描画する
    drawLine(nextStation, context) {
        context.beginPath();

        // 線を引く始点に移動
        context.moveTo(this.x, this.y);

        // 始点から終点まで線を引く
        context.lineTo(nextStation.x, nextStation.y);

        // 線の色
        context.strokeStyle = "white";

        // 線の太さ
        context.lineWidth = 3;

        // 線を描画する
        context.stroke();
    }

}