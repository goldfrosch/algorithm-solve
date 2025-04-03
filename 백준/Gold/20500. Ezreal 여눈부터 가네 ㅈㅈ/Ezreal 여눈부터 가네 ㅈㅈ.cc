#include <iostream>

using namespace std;

int DP[1516];

int main() {
    // https://www.acmicpc.net/problem/20500
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;
    const int ElseCase = 1000000007;

    DP[1] = 0;
    DP[2] = 1;
    // DP[2] => 15, 51, 55, 11 -> 뒷자리가 무조건 5여야 함. -> 15, 55 -> 각 자리 수 합이 총 3의 배수여야 함 -> 15
    // DP[3] => 115, 515, 555, 111, 155, 551, ... 사실 자리 위치는 의미 없음
    // DP[3] => 555 만이 이에 해당됨 -> 1 (DP[2] + '5') -> 1개의 케이스만 존재함.
    // DP[4] => 1115, 1515, 5515, 5555 -> 1개의 케이스 (151 만 케이스에 해당됨)
    // DP[5] => 11115, 11155, 11555, 15555 -> 15555 만 이에 해당됨
    // DP[6] => 111115, 111155, 111555, 115555, 155555, 555555 -> 111555, 555555 가 이에 해당됨
    for (int i = 3; i <= N; i++) {
        if (i % 2 == 0) {
            DP[i] = (DP[i - 1] * 2 + 1) % ElseCase;
        } else {
            DP[i] = (DP[i - 1] * 2 - 1) % ElseCase;
        }
    }

    printf("%d", DP[N]);

    return 0;
}