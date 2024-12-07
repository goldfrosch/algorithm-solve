#include <iostream>

using namespace std;

int NL[1002];

int main()
{
    int N;
    std::cin >> N;

    NL[1] = 1;
    NL[2] = 3;

    for (int i = 3; i <= N; i++) {
        NL[i] = NL[i - 1] + (NL [i - 2] * 2);
        NL[i] %= 10007;
    }

    std::cout << NL[N] << std::endl;

    return 0;
}