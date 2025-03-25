#include <iostream>

using namespace std;

int Triangle[500][500];
int DP[500][500];

// DP[1] = 7
// DP[2] = 7 + 3 , 7 + 8 -> 7 + 8
// DP[3] = 10 + 8, 10 + 1, 15 + 1, 15 + 0 -> 10 + 8
// DP[4] = 18 + 2, 18 + 7, 11 + 7, 11 + 4, 16 + 4, 15 + 4

int main() {
    // https://www.acmicpc.net/problem/1932
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            std::cin >> Triangle[i - 1][j - 1];
        }
    }

    if (N == 1) {
        printf("%d", Triangle[0][0]);
        return 0;
    }

    DP[0][0] = Triangle[0][0];
    int Result = 0;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                DP[i - 1][j - 1] = Triangle[i - 1][j - 1] + DP[i - 2][0];
            }
            else if (j == i) {
                DP[i - 1][j - 1] = Triangle[i - 1][j - 1] + DP[i - 2][j - 2];
            }
            else {
                DP[i - 1][j - 1] = Triangle[i - 1][j - 1] +
                        max(DP[i - 2][j - 2], DP[i - 2][j - 1]);
            }

            if (i == N) {
                Result = max(Result, DP[i - 1][j - 1]);
            }
        }
    }

    printf("%d", Result);

    return 0;
}