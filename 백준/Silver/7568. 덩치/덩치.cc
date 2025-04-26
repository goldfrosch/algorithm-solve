#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/7568
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    int Height[52];
    int Weight[52];

    for (int i = 0; i < N; i++) {
        std::cin >> Weight[i] >> Height[i];
    }

    for (int i = 0; i < N ;i++) {
        int Rank = 1;
        for (int j = 0; j < N; j++) {
            if (Weight[i] < Weight[j] && Height[i] < Height[j]) {
                Rank += 1;
            }
        }

        printf("%d\n", Rank);
    }

    return 0;
}