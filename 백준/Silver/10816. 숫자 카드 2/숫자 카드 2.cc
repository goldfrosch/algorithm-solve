#include <iostream>
#include<unordered_map>

using namespace std;

unordered_map<int, int> Card;

int main() {
    // https://www.acmicpc.net/problem/10816
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int Temp;
        std::cin >> Temp;

        Card[Temp] += 1;
    }

    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int Temp;
        std::cin >> Temp;

        printf("%d ", Card[Temp]);
    }


    return 0;
}