#include <iostream>

#define lld long long int

using namespace std;

lld gcd(lld a, lld b) {
    lld r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

lld lcm(lld a, lld b) {
    return (a * b) / gcd(a, b);
}

int main() {
    // https://www.acmicpc.net/problem/13241
    lld A, B;
    std::cin >> A >> B;

    lld Result = lcm(A, B);

    printf("%lld", Result);

    return 0;
}