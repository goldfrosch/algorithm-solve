#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/25206
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    float TotalCredit = 0.f;
    float TotalScore = 0.f;
    for (int i = 0; i < 20; i++) {
        string Subject;
        float Credit;
        string Score;

        std::cin >> Subject >> Credit >> Score;

        if (Score == "P") {
            continue;
        }

        TotalCredit += Credit;

        float TempScore;

        if (Score == "A+") {
            TempScore = 4.5;
        } else if (Score == "A0") {
            TempScore = 4.0;
        } else if (Score == "B+") {
            TempScore = 3.5;
        } else if (Score == "B0") {
            TempScore = 3.0;
        } else if (Score == "C+") {
            TempScore = 2.5;
        } else if (Score == "C0") {
            TempScore = 2.0;
        } else if (Score == "D+") {
            TempScore = 1.5;
        } else if (Score == "D0") {
            TempScore = 1;
        } else {
            TempScore = 0;
        }

        TotalScore += Credit * TempScore;
    }

    printf("%f", TotalScore / TotalCredit);
}