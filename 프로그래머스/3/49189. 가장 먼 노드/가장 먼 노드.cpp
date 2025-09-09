#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> EdgeList[20001];
bool IsVisited[20001];
map<int, int> EdgeCount;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int MaxCount = 0;

    // 데이터 재정렬하기, 이 과정이 없으면 더 좋긴 하다.
    for (const auto &item: edge) {
        EdgeList[item[0]].push_back(item[1]);
        EdgeList[item[1]].push_back(item[0]);

        IsVisited[item[0]] = false;
        IsVisited[item[1]] = false;
    }

    queue<pair<int, int>> Bfs;
    Bfs.emplace(1, 1);
    IsVisited[1] = true;

    while (!Bfs.empty()) {
        const auto [Edge, Count] = Bfs.front();
        Bfs.pop();

        if (MaxCount < Count) {
            MaxCount = Count;
        }

        for (const auto &item: EdgeList[Edge]) {
            if (IsVisited[item]) {
                continue;
            }

            Bfs.emplace(item, Count + 1);
            EdgeCount[item] = Count + 1;
            IsVisited[item] = true;
        }
    }

    for (const auto &item: EdgeCount) {
        if (item.second == MaxCount) {
            answer += 1;
        }
    }

    return answer;
}