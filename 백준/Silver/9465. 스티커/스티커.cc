#include <iostream>

using namespace std;

int DP[2][100005];

int main() {
    // https://www.acmicpc.net/problem/9465
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N, Result;

    std::cin >> T;

    for (int index = 0; index < T; index++) {
        std::cin >> N;

        for (auto & i : DP) {
            for (int j = 1; j <= N; j++) {
                std::cin >> i[j];
            }
        }

        DP[0][1] += DP[1][0];
        DP[1][1] += DP[0][0];

        for (int i = 2; i <= N; i++) {
            // 해당 위치의 스티커를 찢을 때 그 아래의 뒤 스티커 중 하나를 뜯는다.
            DP[0][i] += max(DP[1][i - 1], DP[1][i - 2]);
            DP[1][i] += max(DP[0][i - 1], DP[0][i - 2]);
        }

        Result = max(DP[0][N], DP[1][N]);
        printf("%d\n", Result);
    }

    return 0;
}