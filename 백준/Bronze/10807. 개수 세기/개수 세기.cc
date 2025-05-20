#include <iostream>

using namespace std;

int List[101];

int main() {
    // https://www.acmicpc.net/problem/10807
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, V;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> List[i];
    }

    std::cin >> V;

    int Result = 0;
    for (int i = 0; i < N; i++) {
        if (List[i] == V) {
            Result += 1;
        }
    }

    printf("%d", Result);

    return 0;
}