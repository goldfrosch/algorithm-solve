#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/10430
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    std::cin >> A >> B >> C;

    printf("%d\n", (A + B) % C);
    printf("%d\n", ((A % C) + (B % C)) % C);
    printf("%d\n", (A * B) % C);
    printf("%d", ((A % C) * (B % C)) % C);


    return 0;
}