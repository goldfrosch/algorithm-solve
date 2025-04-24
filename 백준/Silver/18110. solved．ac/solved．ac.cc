#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/18110
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    if (N == 0) {
        printf("0");
        return 0;
    }

    vector<int> Score;

    for (int i = 0; i < N; i++) {
        int Temp;
        std::cin >> Temp;
        Score.push_back(Temp);
    }

    sort(Score.begin(), Score.end());

    int RemoveCount = round(N * 0.15);
    double Value = 0;

    for (int i = RemoveCount; i < N - RemoveCount; i++) {
        Value += Score[i];
    }

    int Result = round(Value / (N - RemoveCount * 2));

    printf("%d", Result);

    return 0;
}