#include <string>
#include <vector>

using namespace std;

const pair<int, int> Dir[8] = {{1,1}, {1, 0}, {1, -1}, {0,1}, {0,-1}, {-1, 1}, {-1, 0}, {-1,-1}};

bool IsVisited[100][100];

int solution(vector<vector<int>> board) {
    int answer = 0;
    int BoardSize = board.size();

    for (int y = 0; y < BoardSize; y++) {
        for (int x = 0; x < BoardSize; x++) {
            IsVisited[y][x] = false;
        }
    }

    for (int y = 0; y < BoardSize; y++) {
        for (int x = 0; x < BoardSize; x++) {
            if (board[y][x] == 0) {
                continue;
            }

            IsVisited[y][x] = true;
            for (const auto &item: Dir) {
                if (y + item.second >= 0 && y + item.second < BoardSize &&  x + item.first >= 0 && x + item.first < BoardSize) {
                    IsVisited[y + item.second][x + item.first] = true;
                }
            }
        }
    }

    for (int y = 0; y < BoardSize; y++) {
        for (int x = 0; x < BoardSize; x++) {
            if (!IsVisited[y][x]) {
                answer += 1;
            }
        }
    }

    return answer;
}