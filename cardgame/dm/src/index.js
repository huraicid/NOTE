const COLUMN_DEFS = ["Deck Name", "Wins", "Loses", "WP"];
const ROW_DATAS = [["ネバー・エンディング・ヒーロー", "0", "1", "0.0"],["ヘヴィ・デス・メタル", "1", "1", "0.5"],["ビクトリー・ソウル", "1", "1", "0.5"],["BATTLE of YAMATO魂", "2", "0", "1.0"],["Arcadias騎士団", "0", "1", "0.0"]];
const COUNT = 4;

new gridjs.Grid({
    sort: true,
    width: '100%',
    columns: COLUMN_DEFS,
    data: ROW_DATAS
}).render(document.getElementById("wrapper"));

document.getElementById("count").innerText = COUNT;