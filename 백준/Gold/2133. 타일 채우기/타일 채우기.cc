#include <bits/stdc++.h>

using namespace std;

int N;
int DP[30];

int main() {
    std::cin >> N;
    DP[0] = 1;
    DP[2] = 3;
    if (N % 2 == 1) {
        std::cout << 0;
        return 0;
    }

    if (N == 2) {
        std::cout << DP[2];
        return 0;
    }

    for (int i = 4; i <= N; i += 2) {
        DP[i] = DP[i - 2] * DP[2];
        for (int j = i - 4; j >= 0; j -= 2) {
            DP[i] += DP[j] * 2;
        }
    }

    std::cout << DP[N];
    return 0;
}