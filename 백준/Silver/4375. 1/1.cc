#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/4375
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N) {
        int Value = 1;
        int Result = 1;

        for (int i = 1; i <= N; i++) {
            if (Value % N == 0) {
                break;
            }
            Result += 1;
            Value = Value * 10 + 1;
            Value %= N;
        }
        printf("%d\n", Result);
    }

    return 0;
}