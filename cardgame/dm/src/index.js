const COLUMN_DEFS = ["Deck Name", "Wins", "Loses", "WP"];
const ROW_DATAS = [["ネバー・エンディング・ヒーロー", "0", "3", "0.0"],["ヘヴィ・デス・メタル", "2", "1", "0.66"],["ビクトリー・ソウル", "1", "1", "0.5"],["BATTLE of YAMATO魂", "2", "0", "1.0"],["Arcadias騎士団", "1", "1", "0.5"]];
const COUNT = 6;

new gridjs.Grid({
    sort: true,
    width: '100%',
    columns: COLUMN_DEFS,
    data: ROW_DATAS
}).render(document.getElementById("wrapper"));

document.getElementById("count").innerText = COUNT;