#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> adj(n + 1);
    for (auto &w : wires) {
        int a = w[0], b = w[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto count_with_cut = [&](int s, int cut_u, int cut_v) {
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        int cnt = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            cnt++;
            for (int v : adj[u]) {
                // (cut_u, cut_v) 간선을 끊었다고 가정하고 스킵
                if ((u == cut_u && v == cut_v) || (u == cut_v && v == cut_u)) continue;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return cnt;
    };

    int answer = n;
    for (auto &w : wires) {
        int a = w[0], b = w[1];
        int cnt = count_with_cut(a, a, b); // a쪽 컴포넌트 크기
        // 두 컴포넌트 크기 차이 = |(n - cnt) - cnt| = |n - 2*cnt|
        answer = min(answer, abs(n - 2 * cnt));
    }
    return answer;
}