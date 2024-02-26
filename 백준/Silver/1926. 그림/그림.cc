#include <iostream>
#include <vector>
#include <queue>

#define Y first
#define X second

using namespace std;

int H, W;
int board[502][502];

bool isVisit[502][502];

const vector<pair<int,int>> moveDirection = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    std::cin >> H >> W;

    vector<pair<int, int>> structure;

    int maxSize = 0;
    int count = 0;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            std::cin >> board[i][j];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (isVisit[i][j] || board[i][j] == 0) continue;

            queue<pair<int,int>> queue;
            queue.emplace(i, j);

            int tempSize = 0;

            count++;
            while (!queue.empty()) {
                const auto firstQueue = queue.front();
                isVisit[firstQueue.Y][firstQueue.X] = true;

                for (auto value : moveDirection) {
                    const auto nextY = firstQueue.Y + value.Y;
                    const auto nextX = firstQueue.X + value.X;

                    if (nextY < 0 || nextY >= H || nextX < 0 || nextX >= W) continue;
                    if (isVisit[nextY][nextX] || board[nextY][nextX] == 0) continue;
                    isVisit[nextY][nextX] = true;
                    queue.emplace(nextY, nextX);
                }
                tempSize++;
                auto copy = queue;
                while (!copy.empty()) {
                    copy.pop();
                }
                queue.pop();
            }


            maxSize = max(maxSize, tempSize);
        }
    }

    std::cout << count << "\n" << maxSize;
    return 0;
}
