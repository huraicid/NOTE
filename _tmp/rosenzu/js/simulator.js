SimulatorMain = function() {
    // canvas要素を取得する。
    const canvas = document.getElementById('graphArea');

    // アイコン
    const ICON = "🚄";

    // 1秒当たりのアニメーション量
    const STEP = 30;

    // TODO: 一旦初期値
    const nowStation = {x: 332, y: 540};
    const nextStation = {x: 620, y: 490};
    sec = 41;
    const steps = STEP * sec;

    // 1stepあたりに動かす座標
    const STEP_X = (nextStation.x - nowStation.x) / sec / STEP;
    const STEP_Y = (nextStation.y - nowStation.y) / sec / STEP;

    //-------------------------------------
    // アニメーション開始
    //-------------------------------------
    // 初期位置
    let x = nowStation.x;
    let y = nowStation.y + 67;

    const iconDOMItem = "<div id='simuIcon'>🚄</div>";
    canvas.insertAdjacentHTML("beforeend", iconDOMItem);

    let simuIconDOM = document.getElementById("simuIcon");
    simuIconDOM.style.left = x + "px";
    simuIconDOM.style.top = y + "px";

    let intervalId;
    let stepCount = 0;
    let minutes = 

    intervalId = setInterval( () => {
        // 到着したら停止する
        stepCount++;
        if(stepCount > steps) {
            clearInterval(intervalId);
        }

        // 1分ごとに時計を更新する
        if(stepCount % STEP == 0) {
            // TODO: いい感じに直す
            // 現在時刻を取得する
            let curTimeArray = document.getElementById("time").innerText.split(":");
            // 更新後の時刻を更新する
            document.getElementById("time").innetText = curTimeArray[0] + ":" + Number(curTimeArray[1]) + 1;
        }

        // 座標を移動
        x += STEP_X;
        y += STEP_Y;

        simuIconDOM.style.left = x + "px";
        simuIconDOM.style.top = y + "px";
    },
    1000 / STEP);

}