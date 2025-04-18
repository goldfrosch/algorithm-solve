#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

bool IsPrime[5000002] = {true, };

int main() {
    // https://www.acmicpc.net/problem/29728
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        IsPrime[i] = true;
    }

    IsPrime[1] = false;
    for (int i = 2; i <= sqrt(N); i++) {
        if (!IsPrime[i]) {
            continue;
        }

        for (int j = i * i; j <= N; j += i) {
            IsPrime[j] = false;
        }
    }

    string Temp = "B";
    for (int i = 2; i <= N; i++) {
        if (!IsPrime[i]) {
            Temp += 'B';
        } else {
            if (Temp[i - 2] == 'B') {
                Temp[i - 2] = 'S';
                Temp += 'S';
            } else {
                Temp += 'S';
                reverse(Temp.begin(), Temp.end());
            }
        }

    }

    int BResult = 0;
    int SResult = 0;
    for (int i = 1; i <= N; i++) {
        if (Temp[i - 1] == 'B') {
            BResult += 1;
        } else {
            SResult += 1;
        }
    }

    printf("%d %d", BResult, SResult);

    return 0;
}