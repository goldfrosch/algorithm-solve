#include <iostream>

using namespace std;

int ChargeBackCategory[] = { 500, 100, 50, 10, 5, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int ChargePrice = 1000 - N;

    int Result = 0;
    for (int i : ChargeBackCategory) {
        Result += ChargePrice / i;
        ChargePrice %= i;
    }

    printf("%d", Result);

    return 0;
}