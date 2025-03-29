#include <iostream>

using namespace std;

int Wine[10003];
int DP[10003];

int main() {
    // https://www.acmicpc.net/problem/2156
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> Wine[i];
    }

    DP[1] = Wine[1];
    DP[2] = DP[1] + Wine[2];

    for (int i = 3; i <= N; i++) {
        DP[i] = max(DP[i - 3] + Wine[i - 1] + Wine[i], DP[i - 2] + Wine[i]);
        DP[i] = max(DP[i - 1], DP[i]);
    }

    printf("%d", DP[N]);

    return 0;
}