#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/2303
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    int Result = 0;
    int PersonMaxValue = 0;

    for (int i = 0; i < N; i++) {
        int RandNum[5];

        int MaxValue = 0;

        for (int j = 0; j < 5; j++) {
            std::cin >> RandNum[j];
        }

        for (int bitmask = 1; bitmask < (1 << 5); bitmask++) {
            int BitMaskCount = __builtin_popcount(bitmask);
            int Value = 0;
            if (BitMaskCount == 3) {
                for (int k = 0; k < 5; k++) {
                    if ((bitmask >> k) & 1) {
                        Value += RandNum[k];
                    }
                }
            }

            if (MaxValue < (Value % 10)) {
                MaxValue = (Value % 10);
            }
        }

        if (MaxValue >= PersonMaxValue) {
            Result = i + 1;
            PersonMaxValue = MaxValue;
        }
    }

    printf("%d", Result);

    return 0;
}