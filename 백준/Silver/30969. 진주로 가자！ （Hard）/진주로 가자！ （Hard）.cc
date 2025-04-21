#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<short> Costs;
string D;
long long C;

int main() {
    // https://www.acmicpc.net/problem/2303
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Jinju, Result = 0;
    std::cin >> N;
    Costs.reserve(N);

    for (int i = 0; i < N; i++) {
        std::cin >> D >> C;

        if (D == "jinju") {
            Jinju = C;
        }
        if (C > 1000) {
            Result += 1;
        } else {
            Costs.push_back(C);
        }
    }

    sort(Costs.begin(), Costs.end());

    printf("%d\n", Jinju);
    Result += (Costs.size() - (upper_bound(Costs.begin(), Costs.end(), Jinju) - Costs.begin()));

    printf("%d", Result);

    return 0;
}