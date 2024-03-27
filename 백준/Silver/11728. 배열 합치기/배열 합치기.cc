#include <iostream>

using namespace std;

int N, M;

int a[1000001];
int b[1000001];
int c[2000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];

    int aidx = 0, bidx = 0;

    for (int i = 0; i < N + M; i++) {
        if (bidx == M) {
            c[i] = a[aidx++];
        }
        else if (aidx == N) {
            c[i] = b[bidx++];
        }
        else if (a[aidx] <= b[bidx]) c[i] = a[aidx++];
        else c[i] = b[bidx++];
    }

    for (int i = 0; i < N + M; i++) std::cout << c[i] << " ";

    return 0;
}
