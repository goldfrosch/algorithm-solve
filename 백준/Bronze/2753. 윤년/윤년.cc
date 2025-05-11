#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/2753
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    printf("%d", N % 4 == 0 && (N % 100 != 0 || N % 400 == 0));

    return 0;
}