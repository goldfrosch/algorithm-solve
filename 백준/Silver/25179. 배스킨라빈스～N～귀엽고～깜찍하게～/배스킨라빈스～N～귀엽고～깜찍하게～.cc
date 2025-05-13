#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/25179
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int N, M;
    std::cin >> N >> M;

    if ((N - 1) % (M + 1) != 0) {
        printf("Can win");
    } else {
        printf("Can't win");
    }

    return 0;
}