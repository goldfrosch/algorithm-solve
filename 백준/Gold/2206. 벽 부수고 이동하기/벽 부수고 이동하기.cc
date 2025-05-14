#include <iostream>
#include <queue>
#include <string>

using namespace std;

int Board[1001][1001];
bool IsVisited[1001][1001][2]; // [y][x][벽을 부쉈는지 여부]

int DirectionX[4] = {0, 0, 1, -1};
int DirectionY[4] = {1, -1, 0, 0};

struct Params {
    int y, x;
    int broken;
    int distance;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 문자열로 입력 받기
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            Board[i][j] = row[j] - '0'; // 문자를 숫자로 변환
        }
    }

    queue<Params> Queue;
    Queue.push({0, 0, 0, 1}); // y, x, 벽을 부쉈는지 여부, 이동 거리
    IsVisited[0][0][0] = true;

    while (!Queue.empty()) {
        auto [y, x, broken, distance] = Queue.front();
        Queue.pop();

        // 목적지 도달 확인
        if (y == N - 1 && x == M - 1) {
            cout << distance;
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int newY = y + DirectionY[dir];
            int newX = x + DirectionX[dir];

            // 범위 체크
            if (newY < 0 || newY >= N || newX < 0 || newX >= M) {
                continue;
            }

            // 1. 빈 공간으로 이동하는 경우
            if (Board[newY][newX] == 0 && !IsVisited[newY][newX][broken]) {
                IsVisited[newY][newX][broken] = true;
                Queue.push({newY, newX, broken, distance + 1});
            }
            // 2. 벽이 있고, 아직 벽을 부수지 않은 경우
            else if (Board[newY][newX] == 1 && broken == 0 && !IsVisited[newY][newX][1]) {
                IsVisited[newY][newX][1] = true;
                Queue.push({newY, newX, 1, distance + 1});
            }
        }
    }

    cout << -1;
    return 0;
}