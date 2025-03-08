#include <iostream>
#include <map>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1026
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    map<int, bool> Value;
    for (int i = 0; i < N; i++) {
        int Temp;
        std::cin >> Temp;

        Value[Temp] = true;
    }

    int M;
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int Temp;
        std::cin >> Temp;

        printf("%d ", Value[Temp]);
    }

    return 0;
}