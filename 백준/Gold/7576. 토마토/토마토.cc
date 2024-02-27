#include <iostream>
#include <queue>
#include <set>

#define Y first
#define X second

using namespace std;

int H, W;

int remainTomato = 0;

int board[1002][1002];

const vector<pair<int, int>> moveDirection = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    queue<pair<int, int>> queue;
    pair<int, int> lastPosition;
    std::cin >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> board[i][j];
            if (board[i][j] == 0) {
                remainTomato++;
            } else if (board[i][j] == 1) {
                queue.emplace(i, j);
            }
        }
    }

    while (!queue.empty()) {
        const auto currentPos = queue.front();

        for (const auto & value : moveDirection) {
            const auto nextPosY = currentPos.Y + value.Y;
            const auto nextPosX = currentPos.X + value.X;
            if (nextPosY < 0 || nextPosY >= H || nextPosX < 0 || nextPosX >= W) continue;
            if (board[nextPosY][nextPosX] >= 1 || board[nextPosY][nextPosX] == -1) continue;

            queue.emplace(nextPosY, nextPosX);
            board[nextPosY][nextPosX] = board[currentPos.Y][currentPos.X] + 1;
            lastPosition = {nextPosY, nextPosX};
            remainTomato--;
        }
        queue.pop();
    }

    if (remainTomato != 0) {
        std::cout << -1;
        return 0;
    }

    std::cout << board[lastPosition.Y][lastPosition.X] - 1;

    return 0;
}
