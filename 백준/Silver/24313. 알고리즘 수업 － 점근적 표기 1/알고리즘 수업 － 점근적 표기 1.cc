#include <iostream>

using namespace std;

int List[101];

int main() {
    // https://www.acmicpc.net/problem/24313
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A1, A0, C, N;
    std::cin >> A1 >> A0;
    std::cin >> C;
    std::cin >> N;

    printf("%d", A1 * N + A0 <= C * N && A1 <= C);

    return 0;
}