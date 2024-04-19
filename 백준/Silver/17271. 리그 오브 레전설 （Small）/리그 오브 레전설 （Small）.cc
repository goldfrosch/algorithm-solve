#include <iostream>

using namespace std;

const auto MAX_DIVIDE = 1000000007;

int N, M;
int dp[10005] = {1, };

int main() {

    std::cin >> N >> M;

    dp[M] = 2;

    for (int i = 1; i < M; i++) {
        dp[i] = 1;
    }

    for (int i = M; i <= N; i++) {
        dp[i] = dp[i - 1];

        if (i - M >= 0) {
            dp[i] +=  dp[i - M];
        }
        dp[i] %= MAX_DIVIDE;
    }

    std::cout << dp[N];

    return 0;
}