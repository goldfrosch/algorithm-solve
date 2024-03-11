#include <iostream>
#include <stack>
#include <vector>

#define y first
#define x second

using namespace std;

int N, M;

int result = 0;

bool isPeak;

int mount[101][101];
bool isVisit[101][101];

vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

void dfs(pair<int, int> position) {
    for (const auto & dir: direction) {
        const auto ny = position.y + dir.y;
        const auto nx = position.x + dir.x;

        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (mount[position.y][position.x] < mount[ny][nx]) {
            isPeak = false;
        }
        if (isVisit[ny][nx]) continue;
        if (mount[ny][nx] == mount[position.y][position.x]) {
         isVisit[ny][nx] = true;
         dfs({ny, nx});
        }
    }
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> mount[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (isVisit[i][j]) continue;
            
            isPeak = true;
            isVisit[i][j] = true;
            dfs({i, j});
            if(isPeak) {
                result++;
            }
        }
    
    std::cout << result;

    return 0;
}
