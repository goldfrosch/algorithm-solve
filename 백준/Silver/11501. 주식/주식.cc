#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> prices(N);
        for (int i = 0; i < N; i++) {
            cin >> prices[i];
        }

        // 뒤에서부터 접근하여 최대 이익 계산
        long long profit = 0;
        int max_price = 0;

        for (int i = N - 1; i >= 0; i--) {
            if (prices[i] > max_price) {
                max_price = prices[i];
            } else {
                profit += max_price - prices[i];
            }
        }

        cout << profit << '\n';
    }

    return 0;
}