const COLUMN_DEFS = ["Deck Name", "Wins", "Loses", "WP"];
const ROW_DATAS = [["DMC-43 ネバー・エンディング・ヒーロー", "0", "7", "0.0"],["DMC-40 ヘヴィ・デス・メタル", "3", "2", "0.6"],["DMC-39 ビクトリー・ソウル", "3", "2", "0.6"],["DMC-45 BATTLE of YAMATO魂", "4", "1", "0.8"],["DMC-46 Arcadias騎士団", "1", "4", "0.2"],["DMC-36 ヘヴン・オブ・ドラゴン", "5", "0", "1.0"]];
const COUNT = 16;

new gridjs.Grid({
    sort: true,
    width: '700px',
    columns: COLUMN_DEFS,
    data: ROW_DATAS.sort()
}).render(document.getElementById("wrapper"));

document.getElementById("count").innerText = COUNT;