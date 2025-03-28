#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    // https://www.acmicpc.net/problem/2609
    int A, B;
    std::cin >> A >> B;

    printf("%d\n", gcd(A, B));
    printf("%d", lcm(A, B));

    return 0;
}