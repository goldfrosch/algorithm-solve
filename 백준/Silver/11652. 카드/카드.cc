#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<long long, long long> Data;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    long long MinNum;

    for (int i = 0; i < N; i++) {
        long long Temp;
        std::cin >> Temp;

        if (i == 0) {
            MinNum = Temp;
        }

        Data[Temp] += 1;
        if (Data[MinNum] < Data[Temp]) {
            MinNum = Temp;
        } else if (Data[MinNum] == Data[Temp]) {
            MinNum = min(MinNum, Temp);
        }
    }

    printf("%lld", MinNum);

    return 0;
}