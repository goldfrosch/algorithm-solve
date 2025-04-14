#include <iostream>
#include <string>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1543
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N, M;
    getline(cin,N);
    getline(cin,M);

    int Result = 0;

    for (int i = 0; i < N.length(); i++) {
        bool IsAdd = true;
        for (int j = 0; j < M.length(); j++) {
            if (N[i + j] != M[j]) {
                IsAdd = false;
                break;
            }
        }

        if (IsAdd) {
            Result += 1;
            i += M.length() - 1;
        }
    }

    printf("%d", Result);

    return 0;
}