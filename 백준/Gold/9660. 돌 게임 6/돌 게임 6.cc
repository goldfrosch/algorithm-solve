#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/9660
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    std::cin >> N;

    if (N % 7 == 0 || N % 7 == 2) {
        printf("CY");
    } else {
        printf("SK");
    }

    return 0;
}