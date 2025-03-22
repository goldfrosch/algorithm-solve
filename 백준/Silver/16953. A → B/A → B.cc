#include <iostream>
#include <queue>

#define lld long long int
using namespace std;

int main() {
    // https://www.acmicpc.net/problem/16953
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    lld A, B;
    std::cin >> A >> B;

    queue<pair<lld, lld>> BFS;
    BFS.emplace(A, 1);

    while (!BFS.empty()) {
        auto [Value, Result] = BFS.front();
        if (Value == B) {
            printf("%lld", Result);
            return 0;
        }

        BFS.pop();

        if (Value * 2 <= B) {
            BFS.emplace(Value * 2, Result + 1);
        }
        if (Value * 10 + 1 <= B) {
            BFS.emplace(Value * 10 + 1, Result + 1);
        }
    }

    printf("-1");

    return 0;
}