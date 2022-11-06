#include <iostream>
#include <random>
#include <vector>
#include <chrono>

using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine gen(seed);

int random(int left, int right) {
    std::uniform_int_distribution<> dist(left, right);
    return dist(gen);
}

bool isAbleCreateRoom(vector<vector<char>> floor, pair<int, int> upperLeftCoodinate, pair<int, int> lowerRightCoondinate) {
    // フロアのサイズを取得しておく
    int floorHeight = floor.size();
    int floorWidth = floor.at(0).size();
    
    // 右端座標がフロア内にあるか
    // 外周1マスは壁が確定することを考慮する
    if(!(lowerRightCoondinate.first < floorWidth - 1 && lowerRightCoondinate.second < floorHeight - 1)) {
        return false;
    }

    // 部屋が重なるかチェック
    for(auto y = upperLeftCoodinate.second - 1; y < lowerRightCoondinate.second + 1; y++) {
        for(auto x = upperLeftCoodinate.first - 1; x < lowerRightCoondinate.first + 1; x++) {
            if(floor[y][x] == '1') {
                return false;
            }
        }
    }

    return true;
}

int main() {
	// フロアのサイズ
	int HEIGHT = 18;
    int WIDTH = 24;

    // 部屋数
    int MAX_ROOM_COUNT = 12;
    int MIN_ROOM_COUNT = 3;

    // 乱数のシード
    std::random_device rnd;

    // 初期化
    vector<vector<char>> floorData(HEIGHT, vector<char>(WIDTH, '0'));

    // 部屋を生成
    int roomCount = 0;
    for(auto i = 0; i < MAX_ROOM_COUNT; i++) {
        // 部屋のサイズを決定する
        int roomHeight = random(3, HEIGHT / 3);
        int roomWidth = random(3, WIDTH / 3);
        
        // 部屋を構成する座標を設定する。
        // 左端と右端の座標で一意に定まる
        pair<int, int> upperLeftCoodinate = make_pair(random(1, WIDTH - 4), random(1, HEIGHT - 4));
        pair<int, int> lowerRightCoondinate = make_pair(upperLeftCoodinate.first + roomWidth, upperLeftCoodinate.second + roomHeight);

        // 部屋が重なる場合はその部屋は作成しない
        if(!isAbleCreateRoom(floorData, upperLeftCoodinate, lowerRightCoondinate)) {
            cout << i << ": Room cannot be created." << endl;
            
            if(i == MAX_ROOM_COUNT - 1 && roomCount < MIN_ROOM_COUNT) {
                cout << "Room is luck(Count=" << roomCount << "). ";
                i--;
                cout << "Restart to i=" << i << "." << endl;
            } 
            
            continue;
        }

        for(auto y = upperLeftCoodinate.second; y < lowerRightCoondinate.second; y++) {
            for(auto x = upperLeftCoodinate.first; x < lowerRightCoondinate.first; x++) {
                floorData[y][x] = '1';
            }
        }

        roomCount++;
        if(i == MAX_ROOM_COUNT - 1 && roomCount < MIN_ROOM_COUNT) {
            cout << "Room is luck(Count=" << roomCount << "). ";
            i--;
            cout << "Restart to i=" << i << "." << endl;
        }
        else {
            cout << i << ": Room can be created." << endl;
        }
    }
    
    // 出力
    for(auto i = 0; i < HEIGHT; i++) {
        for(auto j = 0; j < WIDTH; j++) {
            cout << floorData[i][j];
        }
        cout << endl;
    }

    return 0;
}
