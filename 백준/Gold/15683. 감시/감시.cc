#include <iostream>
#include <vector>

#define y first
#define x second

using namespace std;

int N, M;
int board[9][9];

// 현재 중복 검사를 하는지 체크 함과 동시에 이미 점유한 공간 인지도 활용 가능함.
int isUsed[9][9];

int maxCCTV = 0;
int canSee = 0;
vector<pair<int, int>> cctv;

int viewResult = 0;

void addVertical(pair<int, int> cur, int dir) {
    for (int i = 1; i < N; i++) {
        const auto ny = cur.y + i * dir;

        if (ny < 0 || ny >= N) break;
        if (board[ny][cur.x] == 6) break;
        isUsed[ny][cur.x]++;
    }
}

void removeVertical(pair<int, int> cur, int dir) {
    for (int i = 1; i < N; i++) {
        const auto ny = cur.y + i * dir;

        if (ny < 0 || ny >= N) break;
        if (board[ny][cur.x] == 6) break;
        isUsed[ny][cur.x]--;
    }
}

void addHorizon(pair<int, int> cur, int dir) {
    for (int i = 1; i < M; i++) {
        const auto nx = cur.x + i * dir;

        if (nx < 0 || nx >= M) break;
        if (board[cur.y][nx] == 6) break;
        isUsed[cur.y][nx]++;
    }
}

void removeHorizon(pair<int, int> cur, int dir) {
    for (int i = 1; i < M; i++) {
        const auto nx = cur.x + i * dir;

        if (nx < 0 || nx >= M) break;
        if (board[cur.y][nx] == 6) break;
        isUsed[cur.y][nx]--;
    }
}

void backTrack(int t) {
    if (t == maxCCTV) {
        auto sum = 0;

        // 현재 보이는 시야 갯수를 카운팅
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (isUsed[i][j] > 0 || board[i][j] > 0) sum++;

        if (canSee < sum) {
            canSee = sum;
        }
        return;
    }

    auto cur = cctv[t];
    if (board[cur.y][cur.x] == 1) {
        // 하
        addVertical(cur, 1);
        backTrack(t + 1);
        removeVertical(cur, 1);

        // 우
        addHorizon(cur, 1);
        backTrack(t + 1);
        removeHorizon(cur, 1);

        // 상
        addVertical(cur, -1);
        backTrack(t + 1);
        removeVertical(cur, -1);

        // 좌
        addHorizon(cur, -1);
        backTrack(t + 1);
        removeHorizon(cur, -1);

    } else if (board[cur.y][cur.x] == 2) {
        // 세로
        addVertical(cur, 1);
        addVertical(cur, -1);
        backTrack(t + 1);
        removeVertical(cur, 1);
        removeVertical(cur, -1);

        // 가로
        addHorizon(cur, 1);
        addHorizon(cur, -1);
        backTrack(t + 1);
        removeHorizon(cur, 1);
        removeHorizon(cur, -1);
    }  else if (board[cur.y][cur.x] == 3) {
        // case 하, 우
        addVertical(cur, 1);
        addHorizon(cur, 1);
        backTrack(t + 1);
        removeVertical(cur, 1);
        removeHorizon(cur, 1);

        // case 상, 좌
        addVertical(cur, -1);
        addHorizon(cur, -1);
        backTrack(t + 1);
        removeVertical(cur, -1);
        removeHorizon(cur, -1);

        // case 상, 우
        addVertical(cur, -1);
        addHorizon(cur, 1);
        backTrack(t + 1);
        removeVertical(cur, -1);
        removeHorizon(cur, 1);

        // case 하, 좌
        addVertical(cur, 1);
        addHorizon(cur, -1);
        backTrack(t + 1);
        removeVertical(cur, 1);
        removeHorizon(cur, -1);
    } else if (board[cur.y][cur.x] == 4) {
        addVertical(cur, -1);
        addHorizon(cur, 1);
        addHorizon(cur, -1);
        backTrack(t + 1);
        removeVertical(cur, -1);
        removeHorizon(cur, 1);
        removeHorizon(cur, -1);

        addVertical(cur, 1);
        addHorizon(cur, 1);
        addHorizon(cur, -1);
        backTrack(t + 1);
        removeVertical(cur, 1);
        removeHorizon(cur, 1);
        removeHorizon(cur, -1);

        addVertical(cur, 1);
        addVertical(cur, -1);
        addHorizon(cur, -1);
        backTrack(t + 1);
        removeVertical(cur, 1);
        removeVertical(cur, -1);
        removeHorizon(cur, -1);

        addVertical(cur, 1);
        addVertical(cur, -1);
        addHorizon(cur, 1);
        backTrack(t + 1);
        removeVertical(cur, 1);
        removeVertical(cur, -1);
        removeHorizon(cur, 1);
    } else if (board[cur.y][cur.x] == 5) {
        addVertical(cur, 1);
        addVertical(cur, -1);
        addHorizon(cur, 1);
        addHorizon(cur, -1);

        backTrack(t + 1);
        removeVertical(cur, 1);
        removeVertical(cur, -1);
        removeHorizon(cur, 1);
        removeHorizon(cur, -1);
    }
}

int main() {
    std::cin >> N >> M;

    viewResult = N * M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> board[i][j];
            if (board[i][j] > 0) {
                if (board[i][j] < 6) {
                    cctv.emplace_back(i, j);
                    maxCCTV++;
                }
            }
        }
    }

    backTrack(0);
    auto result = (viewResult - canSee < 0) ? 0 : viewResult - canSee;
    std::cout << result;

    return 0;
}
