#include <iostream>
#include <queue>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1012
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int M, N, K;
        std::cin >> M >> N >> K;

        bool Field[N][M];
        bool IsVisited[N][M];

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                Field[y][x] = false;
                IsVisited[y][x] = false;
            }
        }

        for (int j = 0; j < K; j++) {
            int NewX, NewY;
            std::cin >> NewX >> NewY;
            Field[NewY][NewX] = true;
        }

        int Result = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (IsVisited[y][x]) {
                    continue;
                }

                if (!Field[y][x]) {
                    continue;
                }

                Result += 1;
                queue<pair<int, int>> BFS;
                BFS.emplace(y, x);
                IsVisited[y][x] = true;

                while (!BFS.empty()) {
                    auto [ny, nx] = BFS.front();
                    BFS.pop();

                    if (ny + 1 < N && Field[ny + 1][nx] && !IsVisited[ny + 1][nx]) {
                        BFS.emplace(ny + 1, nx);
                        IsVisited[ny + 1][nx] = true;
                    }
                    if (ny >= 0 && Field[ny - 1][nx] && !IsVisited[ny - 1][nx]) {
                        BFS.emplace(ny - 1, nx);
                        IsVisited[ny - 1][nx] = true;
                    }
                    if (nx + 1 < M && Field[ny][nx + 1] && !IsVisited[ny][nx + 1]) {
                        BFS.emplace(ny, nx + 1);
                        IsVisited[ny][nx + 1] = true;
                    }
                    if (nx - 1 >= 0 && Field[ny][nx - 1] && !IsVisited[ny][nx - 1]) {
                        BFS.emplace(ny, nx - 1);
                        IsVisited[ny][nx - 1] = true;
                    }
                }
            }
        }

        printf("%d\n", Result);
    }

    return 0;
}