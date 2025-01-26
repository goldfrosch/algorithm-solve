#include <iostream>

using namespace std;

int Value[100010];
int DP[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> Value[i];
    }

    int Result = Value[0];
    DP[0] = Value[0];

    for (int i = 1; i < N; i++) {
        DP[i] = max(DP[i - 1] + Value[i], Value[i]);
        Result = max(DP[i], Result);
    }

    printf("%d", Result);

    return 0;
}