const COLUMN_DEFS = ["Deck Name", "Wins", "Loses", "WP"];
const ROW_DATAS = [["DMC-43 ネバー・エンディング・ヒーロー", "0", "6", "0.0"],["DMC-40 ヘヴィ・デス・メタル", "3", "1", "0.75"],["DMC-39 ビクトリー・ソウル", "3", "1", "0.75"],["DMC-45 BATTLE of YAMATO魂", "4", "0", "1.0"],["DMC-46 Arcadias騎士団", "1", "3", "0.25"]];
const COUNT = 11;

new gridjs.Grid({
    sort: true,
    width: '700px',
    columns: COLUMN_DEFS,
    data: ROW_DATAS.sort()
}).render(document.getElementById("wrapper"));

document.getElementById("count").innerText = COUNT;