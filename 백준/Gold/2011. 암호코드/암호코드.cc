#include <iostream>

using namespace std;

const auto MAX = 1000000;
string N;
int dp[5002];

int main() {
    std::cin >> N;

    if (N[0] == '0') {
        cout << 0;
        return 0;
    }

    auto size = N.size();

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= size; i++) {
        if (N[i - 1]!='0') dp[i] = dp[i - 1];

        auto tempValue = stoi(N.substr(i - 2, 2));
        if (tempValue >= 10 && tempValue <= 26) dp[i] = (dp[i] + dp[i - 2]) % MAX;
    }

    std::cout << dp[size] % MAX;

    return 0;
}
