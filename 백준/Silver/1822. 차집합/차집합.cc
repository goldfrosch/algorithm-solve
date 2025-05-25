#include <iostream>
#include <map>

using namespace std;

map<int, bool> AList;

int main() {
    // https://www.acmicpc.net/problem/1822
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int Temp;
        std::cin >> Temp;

        AList[Temp] = true;
    }

    for (int i = 0; i < M; i++) {
        int Temp;
        std::cin >> Temp;
        AList.erase(Temp);
    }

    printf("%zu\n", AList.size());

    for (const auto &item: AList) {
        printf("%d ", item.first);
    }

    return 0;
}