#include <bits/stdc++.h>

using namespace std;

int temp[2000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        temp[a+1000000]++;
    }
    for (int i = 0; i <= 2000000; i++) {
        while(temp[i]--) {
            std::cout << i - 1000000 << "\n";
        }
    }

    return 0;
}
