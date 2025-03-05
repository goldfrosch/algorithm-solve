#include <iostream>
#include <algorithm>

using namespace std;

bool CompareBig(int a, int b) {
    return a > b;
}

int Compare1[102];
int Compare2[102];

int main() {
    // https://www.acmicpc.net/problem/1026
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> Compare1[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> Compare2[i];
    }

    sort(Compare1, Compare1 + N);
    sort(Compare2, Compare2 + N, CompareBig);

    int Result = 0;

    for (int i = 0; i < N; i++) {
        Result += (Compare1[i] * Compare2[i]);
    }

    printf("%d", Result);

    return 0;
}