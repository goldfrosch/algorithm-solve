#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1193
    int N;
    std::cin >> N;

    int i = 1;
    while (N > i) {
        N -= i;
        i++;
    }

    if (i % 2 == 1) {
        printf("%d/%d", i + 1 - N, N);
    } else {
        printf("%d/%d", N, i + 1 - N);
    }

    return 0;
}