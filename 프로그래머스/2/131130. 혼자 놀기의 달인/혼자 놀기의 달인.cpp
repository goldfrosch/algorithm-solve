#include <vector>
#include <algorithm>
using namespace std;

vector<int> p, sz;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
}

int solution(vector<int> cards) {
    int n = (int)cards.size();
    p.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i) p[i] = i;

    for (int i = 1; i <= n; ++i) {
        unite(i, cards[i - 1]);
    }

    // 루트만 크기 집계
    int first = 0, second = 0;
    for (int i = 1; i <= n; ++i) {
        if (find(i) != i) continue;
        int cur = sz[i];
        if (cur > first) { second = first; first = cur; }
        else if (cur > second) { second = cur; }
    }

    if (second == 0) return 0;
    return first * second;
}