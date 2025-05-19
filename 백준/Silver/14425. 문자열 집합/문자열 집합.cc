#include <iostream>
#include <map>

using namespace std;

map<string, bool> List;

int main() {
    // https://www.acmicpc.net/problem/14425
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string Temp;
        std::cin >> Temp;

        List[Temp] = true;
    }

    int Result = 0;
    for (int i = 0; i < M; i++) {
        string Temp;
        std::cin >> Temp;

        if (List[Temp]) {
            Result += 1;
        }
    }

    printf("%d", Result);

    return 0;
}