#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1205
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    long long int Score;

    std::cin >> N >> Score >> P;

    if (N == 0) {
        printf("1");
        return 0;
    }

    int Result = 1;
    int Count = 0;

    for (int i = 0; i < N; i++) {
        long long int Temp;
        std::cin >> Temp;

        if (Temp > Score) {
            Result += 1;
        } else if (Temp < Score) {
            break;
        }

        Count += 1;
    }

    if (Count == P) {
        printf("-1");
        return 0;
    }

    printf("%d", Result);
    return 0;
}