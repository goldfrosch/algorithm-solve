#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/29700
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;

    int Result = 0;
    for (int i = 0; i < N; i++) {
        int TempData = 0;

        string Temp;
        std::cin >> Temp;
        for (int j = 0; j < M; j++) {
            if (Temp[j] == '0') {
                TempData += 1;
            } else {
                Result += max(0, TempData - (K - 1));
                TempData = 0;
            }
        }

        Result += max(0, TempData - (K - 1));
    }

    printf("%d", Result);

    return 0;
}