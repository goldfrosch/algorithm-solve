#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1120
    string A, B;
    std::cin >> A >> B;

    int Result = 51;
    for (int i = 0; i <= B.length() - A.length(); i++) {
        int Temp = 0;
        for (int j = 0; j < A.length(); j++) {
            if (A[j] != B[i + j]) {
                Temp += 1;
            }
        }

        Result = min(Temp, Result);
    }

    printf("%d", Result);

    return 0;
}