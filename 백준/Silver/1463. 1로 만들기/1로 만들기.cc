#include <iostream>

using namespace std;

int N;
int NL[1000001];

int main() {
    std::cin >> N;

    NL[1] = 0;
    for (int i = 2; i <= N; i++) {
        NL[i] = NL[i - 1] + 1;

        if (i % 2 == 0) NL[i] = min(NL[i], NL[i / 2] + 1);
        if (i % 3 == 0) NL[i] = min(NL[i], NL[i / 3] + 1);
    }

    std::cout << NL[N];

    return 0;
}
