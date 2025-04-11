#include <iostream>

using namespace std;
int DP[42];

int main() {
    // https://www.acmicpc.net/problem/1003
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        std::cin >> N;

        if (N < 2) {
            if (N == 0) {
                printf("1 0\n");
            }
            else {
                printf("0 1\n");
            }
        }
        else {
            DP[0] = 1;
            DP[1] = 1;
            for (int j = 2; j <= N; j++) {
                DP[j] = DP[j - 1]+ DP[j - 2];
            }

            printf("%d %d\n", DP[N - 2], DP[N - 1]);
        }
    }

    return 0;
}