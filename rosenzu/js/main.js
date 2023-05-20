window.onload = function() {
    // canvas要素を取得する。
    const canvas = document.getElementById('graphArea');

    // コンテキストを取得しておく。
    const context = canvas.getContext('2d');


    // 表示する駅を格納する
    const stations = {};

    // 広島駅
    let hiroshima = "Hiroshima"
    let hiroshimaStation = new Station(hiroshima, 332, 540, ["Okayama"]);
    stations[hiroshima] = hiroshimaStation

    // 岡山駅
    let okayama = "Okayama";
    let okayamaStation = new Station(okayama, 620, 490, ["Hiroshima"]);
    stations[okayama] = okayamaStation

    // 路線を描画する。
    for(const name in stations) {
        let nextStations = stations[name].nextStations;
        if(nextStations == null || nextStations.length == 0) {
            break;
        }

        for(next of nextStations) {
            stations[name].drawLine(stations[next], context);
        }
    }

    // 駅を描画する。
    for(const name in stations) {
        stations[name].draw(context);
        stations[name].drawName(context);
    }
};