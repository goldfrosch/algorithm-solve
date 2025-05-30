#include <iostream>
#include <algorithm>

using namespace std;

int Arr[10];
int Num[10];

int N, M;

void Seq(int x, int size) {
    // M만큼 쌓였을 때
    if (size == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", Arr[i]);
        }
        printf("\n");
        return;
    }

    int last = 0;

    // 현재 숫자 와 마지막 숫자가 다른 경우 즉
    // 중복되는 숫자가 아닌 경우에 대해
    // 값을 저장해 이후에 중복되는 숫자는 제외하고 검색하게 하고
    // 재귀를 다시 실행한다.
    for (int i = x; i < N; i++) {
        if (Num[i] != last) {
            Arr[size] = Num[i];
            last = Arr[size];
            Seq(i, size + 1);
        }
    }
}

int main() {
    // https://www.acmicpc.net/problem/15666
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> Num[i];
    }

    // 중복 수열 방지를 위해 sort를 먼저 한다. (같은 숫자 비교를 위함)
    sort(Num, Num + N);

    Seq(0, 0);

    return 0;
}