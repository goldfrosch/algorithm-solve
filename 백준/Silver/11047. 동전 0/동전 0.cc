#include <iostream>

using namespace std;

int K, N;
int coins[14];

int main() {
    int maxCoin, result = 0;
    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        std::cin >> coins[i];

        if (coins[maxCoin] < coins[i] && coins[i] <= K) {
            maxCoin = i;
        }
    }

    while (maxCoin >= 0) {
        auto add = K / coins[maxCoin];
        result += add;
        K -= add * coins[maxCoin];
        maxCoin--;
    }

    std::cout << result;

    return 0;
}