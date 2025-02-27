#include <iostream>

using namespace std;


int main() {
    // https://www.acmicpc.net/problem/9659
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    std::cin >> N;

    printf("%s", N % 2 == 1 ? "SK" : "CY");

    return 0;
}