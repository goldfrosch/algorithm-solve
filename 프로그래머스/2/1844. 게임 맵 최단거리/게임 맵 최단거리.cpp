#include <vector>
#include <queue>

using namespace std;

struct BfsData {
    pair<int, int> Pos;
    int Movement;
};

bool IsVisited[101][101];

const pair<int, int> Dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    if (maps[0][0] == 0) {
        return answer;
    }

    pair<int, int> Finish = {maps[0].size() - 1, maps.size() - 1};
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            IsVisited[i][j] = false;
        }
    }

    queue<BfsData> bfs;
    bfs.push({{0, 0}, 1});
    IsVisited[0][0] = true;

    while (!bfs.empty()) {
        const auto [pos, movement] = bfs.front();
        bfs.pop();

        if (pos.first == Finish.first && pos.second == Finish.second) {
            return movement;
        }

        for (const auto &item: Dir) {
            const int newX = pos.first + item.first;
            const int newY = pos.second + item.second;

            if (newX >= 0 && newX <= Finish.first && newY >= 0 && newY <= Finish.second) {
                if (!IsVisited[newY][newX] && maps[newY][newX] == 1) {
                    IsVisited[newY][newX] = true;
                    bfs.push({{newX, newY}, movement + 1});
                }
            }
        }
    }

    return answer;
}