#include <algorithm>
#include <vector>

using namespace std;

vector<int> p;
tuple<int, int, int> t[10000];

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool IsDiffGroup(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) {
        return false;
    }

    if(p[u] == p[v]) p[u] -= 1;
    if (p[u] < p[v]) {
        p[v] = u;
    } else {
        p[u] = v;
    }

    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    p.resize(n + 1, -1);

    for (int i = 0; i < costs.size(); i++) {
        printf("Case: %d, %d -> %d\n", costs[i][0], costs[i][1], costs[i][2]);
        t[i] = {costs[i][2], costs[i][0], costs[i][1]};
    }

    sort(t, t + costs.size());

    int cnt = 0;

    for (int i = 0; i < costs.size(); i++) {
        int a, b, val;
        tie(val, a, b) = t[i];

        if (!IsDiffGroup(a, b)) {
            continue;
        }

        answer += val;
        cnt += 1;

        if (cnt == n) break;
    }

    return answer;
}