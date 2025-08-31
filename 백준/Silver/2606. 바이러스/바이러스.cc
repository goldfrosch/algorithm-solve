#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> Nodes[101];
bool IsVisited[101];

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int start, end;
        std::cin >> start >> end;

        IsVisited[start] = false;
        IsVisited[end] = false;

        Nodes[start].push_back(end);
        Nodes[end].push_back(start);
    }

    int Result = 0;
    queue<int> BFS;
    BFS.push(1);
    IsVisited[1] = true;

    while(!BFS.empty()) {
        int Computer = BFS.front();
        BFS.pop();

        for (const auto &item: Nodes[Computer]) {
            if (!IsVisited[item]) {
                IsVisited[item] = true;
                Result += 1;
                BFS.push(item);
            }
        }
    }

    printf("%d", Result);

    return 0;
}