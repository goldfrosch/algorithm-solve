#include <iostream>

typedef long long ll;

using namespace std;

ll GCD(const ll a, const ll b) {
    if (a % b == 0) {
        return b;
    }
    return GCD(b, a % b);
}

int main() {
    // https://www.acmicpc.net/problem/7432
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string A;
    std::cin >> A;

    ll N[2];

    string Temp;
    int TempArr = 0;
    for (int i = 0; i < A.length(); i++) {
        if (A[i] == ':') {
            N[TempArr] = stoll(Temp);
            Temp = "";
            ++TempArr;
        } else {
            Temp += A[i];
        }
    }
    N[TempArr] = stoll(Temp);

    const ll GCDValue = GCD(N[0], N[1]);

    printf("%lld:%lld", N[0] / GCDValue, N[1] / GCDValue);

    return 0;
}