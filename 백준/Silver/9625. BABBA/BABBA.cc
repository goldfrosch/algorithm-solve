#include <iostream>

using namespace std;

// 첫번째가 A 갯수, 두번째가 B 갯수
pair<int, int> DP[50];

int main() {
    // https://www.acmicpc.net/problem/9625
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    std::cin >> K;

    // 1 -> B
    // 2 -> BA (B가 1개 늘음)
    // 3 -> BAB (A갯수만큼 B가 늘어남)
    // 4 -> BABBA (A가 B로 변경되고 B만큼 A가 추가된다) (1,1)
    // 5 -> BABBABAB (1,2)
    // 6 -> BABBABABBABBA (2,3)
    // 7 -> BABBABABBABBABABBABAB (3,5)

    DP[1] = {0, 1};
    DP[2] = {1,1};
    DP[3] = {1, 2};
    DP[4] = {2, 3};

    if (K <= 4) {
        printf("%d %d", DP[K].first, DP[K].second);
        return 0;
    }

    for (int i = 5; i <= K; i++) {
        DP[i].first = DP[i - 1].second;
        DP[i].second = DP[i - 1].first + DP[i - 1].second;
    }

    printf("%d %d", DP[K].first, DP[K].second);

    return 0;
}