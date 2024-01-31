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
        this.name = name;
        this.x = x;
        this.y = y;
        this.nextStations = nextStations;
    }

    // 駅のオブジェクトをcanvas上に描画する
    draw(context) {
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

    // 駅名をオブジェクト下に描画する
    drawName(context) {
        // フォント
        const FILL_COLOR = "black";
        const FONT_STYLE = "9pt sans-serif"
        
        context.fillStyle = FILL_COLOR;
        context.font = FONT_STYLE;
        context.fillText(this.name, this.x, this.y + 15);
        context.strokeText(this.name, this.x, this.y + 15);
    }

    // 路線をcanvas上に描画する
    drawLine(nextStation, context) {
        context.beginPath();

        // 線を引く始点に移動
        context.moveTo(this.x, this.y);

        // 始点から終点まで線を引く
        context.lineTo(nextStation.x, nextStation.y);

        // 線の色
        context.strokeStyle = "black";

        // 線の太さ
        context.lineWidth = 3;

        // 線を描画する
        context.stroke();
    }

}