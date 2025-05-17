#include <iostream>

using namespace std;

int DP[1005][1005];

int main() {
    // https://www.acmicpc.net/problem/9251
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;

    std::cin >> A >> B;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            // 두 문자열의 값이 같다는 뜻은
            if (A[i] == B[j]) {
                // 이전 각 글자 기준으로 새로운 부분 수열에 1을 더해도 된다는 뜻.
                DP[i + 1][j + 1] = DP[i][j] + 1;
            } else {
                DP[i + 1][j + 1] = max(DP[i][j + 1], DP[i + 1][j]);
            }
        }
    }

    printf("%d", DP[A.size()][B.size()]);

    return 0;
}