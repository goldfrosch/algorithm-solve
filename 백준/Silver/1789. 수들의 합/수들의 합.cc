#include <iostream>
#include <map>

using namespace std;

map<char, char> Parse;

int main() {
    // https://www.acmicpc.net/problem/1789
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long S;
    std::cin >> S;
    long long Sum = 0;
    long long Result = 0;
    for (long long i = 1; i <= S; i++) {
        Sum += i;
        Result = i;
        if (Sum > S) {
            Result -= 1;
            break;
        }
    }

    printf("%lld", Result);

    return 0;
}