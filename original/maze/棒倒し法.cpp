#include <iostream>
#include <vector>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

// オブジェクト定義
const static int WALL = 0;
const static int PATH = 1;
const static int START = 8;
const static int GOAL = 9;

// 方向定義
const static int DIR_EAST = 0;
const static int DIR_WEST = 1;
const static int DIR_SOUTH = 2;
const static int DIR_NORTH = 3;

bool isAbleCreateWall(std::vector<std::vector<int> > mazeData, const int nowX, const int nowY, int dir) {
   // 判定用の座標
    int targetX = nowX;
    int targetY = nowY;
   
    switch(dir) {
    case DIR_EAST:
        targetX += 1;
        break;
    case DIR_WEST:
        targetX -= 1;
        break;
    case DIR_SOUTH:
        targetY += 1;
        break;
    default:
        targetY -= 1;
        break;
    }

    if(mazeData[targetY][targetX] == PATH) {
        return true;
    }

    return false;
}

std::vector<std::vector<int> > initMazeData(int rowSize, int colSize) {
    std::vector<std::vector<int> > rtnMazeData(rowSize, std::vector<int>(colSize, WALL));

    // 棒倒しのために迷路の内側に基準となる壁を残して通路にする
    for(int i = 1; i < rowSize - 1; i++) {
        for(int j = 1; j < colSize - 1; j++) {
            if(i % 2 == 1 || j % 2 == 1) {
                rtnMazeData[i][j] = PATH;
            }
        }
    }

    // 棒倒し法で迷路を生成する
    for(int y = 2; y < rowSize - 1; y += 2) {
        for(int x = 2; x < colSize - 1; x+= 2) {
            // 壁を作る対象の方向を取得する
            // 壁が作れるまで乱数を取得し続ける
            int rndDir = 0;
            while(true) {
                if(y == 2) {
                    std::uniform_int_distribution<> dist(0, 3);
                    rndDir = dist(gen);
                } 
                else {
                    std::uniform_int_distribution<> dist(0, 2);
                    rndDir = dist(gen);
                }

                if(isAbleCreateWall(rtnMazeData, x, y, rndDir)) {
                    break;
                }
            }

            // 壁を生成する
            switch (rndDir) {
            case 0:
                // 東
                rtnMazeData[y][x+1] = WALL;
                break;
            case 1:
                // 西 
                rtnMazeData[y][x-1] = WALL;
                break;
            case 2: 
                // 南
                rtnMazeData[y+1][x] = WALL;
                break;
            default:
                // 北 
                rtnMazeData[y-1][x] = WALL;
                break;
            }
        }
    }

    // 入口と出口を生成する
    rtnMazeData[0][1] = GOAL;
    rtnMazeData[rowSize-1][colSize-2] = START;

    return rtnMazeData;
} 

int main() {
    const int rowSize = 9;
    const int colSize = 9;

    const static int WALL = 0;
    const static int PATH = 1;

    std::vector<std::vector<int> > mazeData = initMazeData(rowSize, colSize);

    for(int i = 0; i < rowSize; i++) {
        for(int j = 0; j < colSize; j++) {
            std::string outChar = "¥0";
            switch (mazeData[i][j]) {
            case PATH:
                outChar = " ";
                break;
            case START:
                outChar = "S";
                break;
            case GOAL:
                outChar = "G";
                break;
            default:
                outChar = "◼︎";
            }

            std::cout << outChar;
        }

        std::cout << std::endl;
    }

    return 0;
}


