#include <iostream>
#include <map>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1269
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    std::cin >> A >> B;

    map<int, bool> Check;

    for (int i = 0; i < A; i++) {
        int Temp;
        std::cin >> Temp;

        Check[Temp] = true;
    }

    for (int i = 0; i < B; i++) {
        int Temp;
        std::cin >> Temp;
        Check[Temp] = !Check[Temp];
    }

    int Result = 0;
    for (const auto [Key, Value] : Check) {
        if (Value) {
            Result += 1;
        }
    }

    printf("%d", Result);

    return 0;
}