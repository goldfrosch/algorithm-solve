#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    unordered_set<string> List;

    for (int i = 0; i < N; i++) {
        string Temp;
        std::cin >> Temp;
        List.insert(Temp);
    }

    set<string> Result;
    for (int i = 0; i < M; i++) {
        string Temp;
        std::cin >> Temp;
        if (List.find(Temp) != List.end()) {
            Result.insert(Temp);
        }
    }

    printf("%zu\n", Result.size());
    for (const auto &item: Result) {
        printf("%s\n", item.c_str());
    }

    return 0;
}