#include <bits/stdc++.h>

using namespace std;

int N;
int DP[100005];

int main() {
    std::cin >> N;

    DP[0] = 1; DP[1] = 3;

    if (N < 2) {
        std::cout << DP[N];
        return 0;
    }

    for (int i = 2; i <= N; i++)
        DP[i] = (DP[i - 2] + DP[i - 1] * 2) % 9901;

    std::cout << DP[N];
    return 0;
}