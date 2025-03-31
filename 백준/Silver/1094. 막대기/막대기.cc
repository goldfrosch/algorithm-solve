#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1094
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    std::cin >> X;

    int Result = 0;
    while (X > 0) {
        if (X % 2 == 1) {
            Result += 1;
        }
        X /= 2;
    }

    printf("%d", Result);

    return 0;
}