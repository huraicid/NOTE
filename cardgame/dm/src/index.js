const COLUMN_DEFS = ["Deck Name", "Wins", "Loses", "WP"];
const ROW_DATAS = [["DMC-43 ネバー・エンディング・ヒーロー", "0", "3", "0.0"],["DMC-40 ヘヴィ・デス・メタル", "2", "1", "0.66"],["DMC-39 ビクトリー・ソウル", "1", "1", "0.5"],["DMC-45 BATTLE of YAMATO魂", "2", "0", "1.0"],["DMC-46 Arcadias騎士団", "1", "1", "0.5"]];
const COUNT = 6;

new gridjs.Grid({
    sort: true,
    width: '700px',
    columns: COLUMN_DEFS,
    loadedRows: function (s, e) {
        s.autoSizeColumns();
    },
    data: ROW_DATAS
}).render(document.getElementById("wrapper"));

document.getElementById("count").innerText = COUNT;