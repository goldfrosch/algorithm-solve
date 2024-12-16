#include <iostream>

using namespace std;

int DP[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        // 우선 전부 1일수도 있으니 i로 초기화함
        DP[i] = i;
        // 1, 4, 9 등 계속 제곱을 올려보면서
        // i - 제곱 (ex 13 - 9 = 4) + 1 과 단순히 1끼리의 조합 중 뭐가 더 작냐부터 시작해
        // 올라가면 올라갈수록의 제곱 값 자체 비교를 진행함
        for (int j = 1; j * j <= i; j++) {
            DP[i] = min(DP[i], DP[i - j * j] + 1);
        }
    }

    std::cout << DP[N];

    return 0;
}