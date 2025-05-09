#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/21966
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;

    std::cin >> N >> S;

    if (N <= 25) {
        printf("%s", S.c_str());
        return 0;
    }

    bool IsOneSentence = true;
    for (int i = 12; i < N - 12; i++) {
        if (S[i] == '.') {
            IsOneSentence = false;
            break;
        }
    }

    if (IsOneSentence) {
        for (int i = 0; i < 11; i++) {
            printf("%c", S[i]);
        }
        printf("...");
        for (int i = N - 11; i < N; i++) {
            printf("%c", S[i]);
        }
    } else {
        for (int i = 0; i < 9; i++) {
            printf("%c", S[i]);
        }
        printf("......");
        for (int i = N - 10; i < N; i++) {
            printf("%c", S[i]);
        }
    }

    return 0;
}