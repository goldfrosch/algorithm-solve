#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/27866
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    std::cin >> s;

    int N;
    std::cin >> N;

    printf("%c", s[N - 1]);

    return 0;
}