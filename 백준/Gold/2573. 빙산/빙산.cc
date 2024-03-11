#include <iostream>
#include <stack>
#include <vector>

#define y first
#define x second

using namespace std;

int result = 0;
int N, M;
int ice[301][301];

bool isEnd = false;

vector<pair<int, int>> currentIce = {{0, 0}};
vector<int> tempIceMelt;
vector<pair<int, int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void meltIce() {
    for (const auto & iceI: currentIce) {
        auto emptyPlace = 0;
        for (const auto & dir: direction) {
            const auto ny = iceI.y + dir.y;
            const auto nx = iceI.x + dir.x;

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (ice[ny][nx] == 0) {
                emptyPlace++;
            }
        }
        tempIceMelt.push_back(emptyPlace);
    }

    for (int i = 0; i < currentIce.size(); i++) {
        const auto cur = currentIce[i];
        ice[cur.y][cur.x] = ice[cur.y][cur.x] - tempIceMelt[i] >= 0 ? ice[cur.y][cur.x] - tempIceMelt[i] : 0;
    }
}

int main() {

    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            std::cin >> ice[i][j];
        }

    while (!currentIce.empty()) {
        currentIce={};
        tempIceMelt = {};
        bool isVisit[301][301] = {};
        isEnd = false;
        stack<pair<int, int>> stack1;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (ice[i][j] > 0) {
                    currentIce.emplace_back(i, j);
                }
            }

        for (const auto & ices: currentIce) {
            if (!isVisit[ices.y][ices.x]) {
                if (isEnd) {
                    std::cout << result;
                    return 0;
                }
                isVisit[ices.y][ices.x] = true;
                stack1.emplace(ices.y, ices.x);

                while(!stack1.empty()) {
                    const auto cur = stack1.top();
                    stack1.pop();

                    for (const auto & dir: direction) {
                        const auto ny = cur.y + dir.y;
                        const auto nx = cur.x + dir.x;

                        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                        if (isVisit[ny][nx] || ice[ny][nx] == 0) continue;

                        isVisit[ny][nx] = true;
                        stack1.emplace(ny, nx);
                    }
                    isEnd = true;
                }
            }
        }

        result++;

        meltIce();
    }

    std::cout << 0;

    return 0;
}
