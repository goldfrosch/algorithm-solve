#include <iostream>

using namespace std;

int Stair[302];
int DP[302];

int main() {
    // https://www.acmicpc.net/problem/2579
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        int Temp;
        std::cin >> Temp;

        Stair[i] = Temp;
    }

    DP[1] = Stair[1];
    DP[2] = DP[1] + Stair[2];
    DP[3] = max(Stair[2], Stair[1]) + Stair[3];

    if (N <= 3) {
        printf("%d", DP[N]);
        return 0;
    }

    for (int i = 4; i <= N; i++) {
        DP[i] = max(DP[i - 2] + Stair[i], DP[i - 3] + Stair[i - 1] + Stair[i]);
    }

    printf("%d", DP[N]);

    return 0;
}