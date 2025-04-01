#include <iostream>

#define PosY first
#define PosX second

using namespace std;

int Y, X;
int Result = 0;
char Map[21][21];
bool IsVisited[26];

int moveToX[4] = {-1, 1, 0, 0};
int moveToY[4] = {0, 0, -1, 1};

void Solve(pair<int, int> Pos, int Value) {
    Result = max(Result, Value);

    for (int i = 0; i < 4; i++) {
        const int ny = Pos.PosY + moveToY[i];
        const int nx = Pos.PosX + moveToX[i];
        if (ny < 0 || ny >= Y
            || nx < 0 || nx >= X) {
            continue;
        }

        const char Next = Map[ny][nx];
        if (IsVisited[Next - 'A']) {
            continue;
        }

        IsVisited[Next - 'A'] = true;
        Solve({ny, nx}, Value + 1);
        IsVisited[Next - 'A'] = false;
    }
}

int main() {
    // https://www.acmicpc.net/problem/1987
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::cin >> Y >> X;

    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            char Temp;
            std::cin >> Temp;
            Map[i][j] = Temp;
        }
    }

    IsVisited[Map[0][0] - 'A'] = true;
    Solve({0, 0}, 1);

    printf("%d", Result);

    return 0;
}