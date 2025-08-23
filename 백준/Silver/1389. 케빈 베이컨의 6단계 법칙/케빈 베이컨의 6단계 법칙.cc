#include <iostream>
#include <queue>

using namespace std;

bool Nodes[101][101];

int main(){
    int N, M;

    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int Start, End;
        std::cin >> Start >> End;

        Nodes[Start][End] = true;
        Nodes[End][Start] = true;
    }

    int ResultNum = 0;
    int KebinBacon = 0;

    for (int i = N; i >= 1; i--) {
        int Temp = 0;

        bool IsVisited[100] = {false, };
        queue<pair<int, int>> Bfs;

        IsVisited[i] = true;
        Bfs.emplace(i, 1);

        while (!Bfs.empty()) {
            auto [PersonNum, Count] = Bfs.front();
            Bfs.pop();

            for (int k = 1; k <= N; k++) {
                if (k == PersonNum) continue;

                if (!IsVisited[k] && Nodes[PersonNum][k]) {
                    IsVisited[k] = true;
                    Temp += Count;

                    Bfs.emplace(k, Count + 1);
                }
            }
        }

        if (i == N) {
            KebinBacon = Temp;
            ResultNum = N;

            continue;
        }

        if (KebinBacon >= Temp) {
            KebinBacon = Temp;
            ResultNum = i;
        }
    }

    printf("%d", ResultNum);

    return 0;
}