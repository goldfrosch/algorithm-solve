#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/9657
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N % 7 == 1 || N % 7 == 3) {
        printf("CY");
    } else {
        printf("SK");
    }

    return 0;
}