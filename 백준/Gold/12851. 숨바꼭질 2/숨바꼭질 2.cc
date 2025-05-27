#include <iostream>
#include <queue>

using namespace std;

bool IsVisited[100005];

int main() {
    // https://www.acmicpc.net/problem/12851
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    IsVisited[N] = true;

    queue<pair<int, int>> Bfs;

    Bfs.emplace(0, N);

    int Answer1 = 99999999;
    int Answer2 = 0;

    while (!Bfs.empty()) {
        const auto [Count, Pos] = Bfs.front();
        Bfs.pop();

        IsVisited[Pos] = true;

        if (Count > Answer1) {
            break;
        }

        if (Pos == K) {
            Answer1 = Count;
            Answer2 += 1;
            continue;
        }

        if (Pos - 1 >= 0 && !IsVisited[Pos - 1]) {
            Bfs.emplace(Count + 1, Pos - 1);
        }
        if (Pos + 1 <= 100000 && !IsVisited[Pos + 1]) {
            Bfs.emplace(Count + 1, Pos + 1);
        }
        if (Pos * 2 <= 100000 && !IsVisited[Pos * 2]) {
            Bfs.emplace(Count + 1, Pos * 2);
        }
    }

    printf("%d\n%d", Answer1, Answer2);

    return 0;
}