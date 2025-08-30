#include <iostream>

using namespace std;

int DP[300001][2];

int main()
{
    int N;
    int Box[300001];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> Box[i];
    }

    for (int i = 0; i < N; i++) {
        DP[i][0] = max(Box[i], DP[i - 1][0] + Box[i]);
    }

    for (int i = N - 1; i >= 0; i--) {
        DP[i][1] = max(Box[i], DP[i + 1][1] + Box[i]);
    }

    for (int i = 0; i < N; i++) {
        int Value = max(Box[i], DP[i][0] + DP[i][1] - Box[i]);
        printf("%d ", Value);
    }

    return 0;
}