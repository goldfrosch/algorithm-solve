#include <iostream>

using namespace std;

string N;
int dp[5002];


int main() {
    std::cin >> N;

    if (N[0] == '0') {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N.size(); i++) {
        if (N[i - 1] != '0') {
            dp[i] = dp[i - 1];
        }

        int tmp = stoi(N.substr(i - 2, 2));
        if (tmp >= 10 && tmp <= 26) {
            dp[i] = (dp[i] + dp[i - 2]) % 1000000;
        }
    }

    cout << dp[N.size()] % 1000000;

    return 0;
}
