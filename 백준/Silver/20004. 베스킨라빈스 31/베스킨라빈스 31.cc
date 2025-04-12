#include <iostream>

using namespace std;

// 명수, N번째 숫자 승패
bool DP[32][32];

int main() {
    // https://www.acmicpc.net/problem/20004
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 2; i <= 31; i++) {
        for (int j = 1; j <= 31; j++) { // 숫자 1부터 31까지
            if (i + 1 >= j) { // 숫자가 i+1 이하인 경우 무조건 이길 수 없음
                DP[i][j] = false;
            } else {
                bool check = true; // 이길 수 있는 상태 확인
                for (int t = 1; t <= i; t++) { // 1~i만큼의 숫자를 부를 수 있음
                    if (DP[i][j - t] == 1) { // 상대방이 이길 수 있는 상태가 존재하면
                        check = false;
                    }
                }
                DP[i][j] = check; // 이길 수 있으면 1, 아니면 0
            }
        }
    }

    printf("1\n");

    for (int i = 2; i <= N; i++) {
        if (DP[i][31]) {
            printf("%d\n", i);
        }
    }
    return 0;
}