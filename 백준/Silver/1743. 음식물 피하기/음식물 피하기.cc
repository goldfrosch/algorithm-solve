#include <iostream>
#include <stack>
#include <vector>

#define Y first
#define X second

using namespace std;

int foodDump[101][101];
int maxSize = 0;
int N,M,K;

vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    stack<pair<int, int>> stack1;

    std::cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int a, b;
        std::cin >> a >> b;
        foodDump[a - 1][b - 1] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (foodDump[i][j] == 1) {
                stack1.emplace(i,j);
                auto tempSize = 0;

                while (!stack1.empty()) {
                    const auto current = stack1.top();
                    foodDump[current.Y][current.X] = -1;
                    stack1.pop();

                    for (auto & dir : direction) {
                        auto nY = dir.Y + current.Y;
                        auto nX = dir.X + current.X;

                        if (nY < 0 || nY >= N || nX < 0 || nX >= M) continue;
                        if (foodDump[nY][nX] != 1) continue;
                        
                        foodDump[nY][nX] = -1;
                        stack1.emplace(nY, nX);
                    }
                    tempSize++;
                }

                if (maxSize < tempSize) {
                    maxSize = tempSize;
                }
            }
        }
    }

    std::cout << maxSize;

    return 0;
}
