#include <iostream>

using namespace std;

long long int Result = 9876543210;

int Sour[10];
int Bitter[10];

int main() {
    // https://www.acmicpc.net/problem/2961
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> Sour[i] >> Bitter[i];
    }

    // 비트 마스킹 으로 10진수 기준 1씩 증가 하는 것이 결국은 모든 경우 수를 탐색할 수 있다.
    for (int bitmask = 1; bitmask < (1 << N); bitmask++) {
        // 신맛은 곱이고, 쓴 맛은 합인 것이 핵심.
        long long int sour = 1, bitter = 0;

        for (int i = 0; i < N; i++) {
            // 현재 비트 마스크 값과 i번째 재료의 합 집합에 값이 존재 하는 지 확인
            // ex. 111 & 010 -> 010 즉 0보다 크기에 참이 된다.
            if (bitmask & (1 << i)) {
                sour *= Sour[i];
                bitter += Bitter[i];
            }
        }

        Result = min(Result, abs(sour - bitter));
    }

    printf("%lld", Result);

    return 0;
}