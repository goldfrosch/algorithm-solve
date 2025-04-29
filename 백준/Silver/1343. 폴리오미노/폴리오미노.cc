#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1343
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    std::cin >> N;

    // 검증 과정
    int CheckValue = 0;
    for (int i = 0; i < N.length(); i++) {
        if (N[i] == '.') {
            if (CheckValue != 0) {
                if (CheckValue % 2 == 1) {
                    printf("-1");
                    return 0;
                }
            }
        } else {
            CheckValue += 1;
        }
    }

    if (CheckValue % 2 == 1) {
        printf("-1");
        return 0;
    }

    CheckValue = 0;
    for (int i = 0; i < N.length(); i++) {
        if (N[i] == '.') {
            if (CheckValue == 0) {
                printf(".");
            } else {
                for (int j = 0; j < CheckValue / 4; j++) {
                    printf("AAAA");
                }

                if (CheckValue % 4 == 2) {
                    printf("BB");
                }

                printf(".");
                CheckValue = 0;
            }
        } else {
            CheckValue += 1;
        }
    }

    if (CheckValue != 0) {
        for (int j = 0; j < CheckValue / 4; j++) {
            printf("AAAA");
        }

        if (CheckValue % 4 == 2) {
            printf("BB");
        }
    }

    return 0;
}