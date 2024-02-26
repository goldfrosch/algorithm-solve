#include <iostream>
#include <queue>
#include <set>

#define Y first
#define X second

using namespace std;

int H, W;

int board[102][102];

const vector<pair<int, int>> moveDirection = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    queue<pair<int, int>> queue({{0, 0}});
    set<pair<int, int>> currentMove;
    std::cin >> H >> W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char road;
            std::cin >> road;
            if (road == '1') {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }

    while(!queue.empty()) {
        const auto current = queue.front();
        for (const auto & direction : moveDirection) {
            const auto newY = direction.Y + current.Y;
            const auto newX = direction.X + current.X;

            if (newY < 0 || newY >= H || newX < 0 || newX >= W) continue;
            if (board[newY][newX] == 0) continue;

            if (board[newY][newX] == 1) {
                board[newY][newX] = board[current.Y][current.X] + 1;
                queue.emplace(newY, newX);
            }
        }
        queue.pop();
    }

    std::cout << board[H - 1][W - 1];

    return 0;
}
