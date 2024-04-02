#include <iostream>

using namespace std;

int N;
int colorVal[1001][3];

int maxVal[1001][3];

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++)
        for(int j = 0; j <= 2; j++) std::cin >> colorVal[i][j];

    maxVal[0][0] = colorVal[0][0];
    maxVal[0][1] = colorVal[0][1];
    maxVal[0][2] = colorVal[0][2];

    for (int i = 1; i < N; i++) {
        maxVal[i][0] = min(maxVal[i - 1][1], maxVal[i - 1][2]) + colorVal[i][0];
        maxVal[i][1] = min(maxVal[i - 1][0], maxVal[i - 1][2]) + colorVal[i][1];
        maxVal[i][2] = min(maxVal[i - 1][0], maxVal[i - 1][1]) + colorVal[i][2];
    }

    std::cout << min(min(maxVal[N - 1][0], maxVal[N - 1][1]), maxVal[N - 1][2]);

    return 0;
}
