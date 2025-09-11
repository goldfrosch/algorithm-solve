#include <vector>
#include <queue>

using namespace std;

struct Bfs {
    pair<int, int> Pos;
    int VisitedCount = 0;
};

int Board[103][103];
bool IsVisited[103][103];
const pair<int, int> Dir[4] = {{1,0}, {-1, 0}, {0,1}, {0,-1}};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    // 보드 값 초기화
    for (int y = 0; y < 103; y ++) {
        for (int x = 0; x < 103; x++) {
            Board[y][x] = 0;
            IsVisited[y][x] = false;
        }
    }

    // 중첩된 사각형 정보 처리
    for (const auto &item: rectangle) {
        for (int i = item[0] * 2; i <= item[2] * 2; i++) {
            for (int j = item[1] * 2; j <= item[3] * 2; j++) {
                if (i == item[0] * 2 || i == item[2] * 2 || j == item[1] * 2 || j == item[3] * 2) {
                    if (Board[j][i] == 0) {
                        Board[j][i] = 2;
                    }
                } else {
                    Board[j][i] = 1;
                }
            }
        }
    }

    queue<Bfs> Bfs;
    Bfs.push({{characterX * 2, characterY * 2}, 0});
    IsVisited[characterY * 2][characterX * 2] = true;

    while (!Bfs.empty()) {
        const auto [Pos, VisitedCount] = Bfs.front();
        Bfs.pop();

        if (Pos.first == itemX * 2 && Pos.second == itemY * 2) {
            return VisitedCount / 2;
        }

        for (const auto &item: Dir) {
            const int NewX = Pos.first + item.first;
            const int NewY = Pos.second + item.second;

            // 더 이상 올 수 없는 공간으로 왔을 때의 예외 처리
            if (NewX < 0 || NewX >= 103 || NewY < 0 || NewY >= 103) {
                continue;
            }

            if (Board[NewY][NewX] != 2) {
                continue;
            }

            if (IsVisited[NewY][NewX]) {
                continue;
            }

            Bfs.push({{NewX, NewY}, VisitedCount + 1});
            IsVisited[NewY][NewX] = true;
        }
    }

    return answer;
}