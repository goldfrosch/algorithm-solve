#include <iostream>

using namespace std;

int DP[100002];

int main() {
    // https://www.acmicpc.net/problem/12865
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int W, V;
        std::cin >> W >> V;

        // 버틸 수 있는 K 무게 부터, 현재 물품 무게까지 내려가면서
        // 해당 물품을 담을 수 있는 지 체크한다.
        for (int j = K; j >= W; j--) {
            // 물건의 최대 값은, 현재 j - W kg에서 현재 물건을 담았을 때의 가치 값과
            // 최대 가치 값과 값을 비교해 더 큰 수를 할당해준다.
            // 초기화는 기본 다 0에서 시작하기 때문에 필요하지 않다.
            DP[j] = max(DP[j - W] + V, DP[j]);
        }
    }
    
    printf("%d", DP[K]);

    return 0;
}