#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int R, C;

string board[1002];

int fire[1002][1002];
int human[1002][1002];

const vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;

    for(int i = 0; i < R; i++){
        fill(fire[i], fire[i] + C, -1);
        fill(human[i], human[i] + C, -1);
    }

    queue<pair<int,int>> fireQueue;
    queue<pair<int,int>> humanQueue;

    for(int i = 0; i < R; i++)
        cin >> board[i];

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(board[i][j] == 'F'){
                fireQueue.emplace(i, j);
                fire[i][j] = 0;
            }
            if(board[i][j] == 'J'){
                humanQueue.emplace(i,j);
                human[i][j] = 0;
            }
        }
    }

    while(!fireQueue.empty()){
        auto cur = fireQueue.front();
        fireQueue.pop();
        for (const auto & dir : direction){
            auto nx = cur.X + dir.X;
            auto ny = cur.Y + dir.Y;

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;

            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            fireQueue.emplace(nx,ny);
        }
    }

    while(!humanQueue.empty()){
        auto cur = humanQueue.front();
        humanQueue.pop();
        for (const auto & dir : direction){
            auto nx = cur.X + dir.X;
            auto ny = cur.Y + dir.Y;

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << human[cur.X][cur.Y] + 1;
                return 0;
            }
            if(human[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(fire[nx][ny] != -1 && fire[nx][ny] <= human[cur.X][cur.Y]+1) continue;

            human[nx][ny] = human[cur.X][cur.Y]+1;
            humanQueue.emplace(nx,ny);
        }
    }

    std::cout << "IMPOSSIBLE";

    return 0;
}
