#include <iostream>

using namespace std;

int N, K;
int coin[102];

int d[10002];

int main() {
    std::cin >> N >> K;

    for (int i = 1; i <= N; i++) std::cin >> coin[i];
    d[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = coin[i]; j <= K; j++) {
            d[j] += d[j - coin[i]];
        }
    }

    std::cout << d[K];

    return 0;
}
