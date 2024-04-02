#include <iostream>

using namespace std;

int N;
int d[12];

int main() {
    std::cin >> N;

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for (int i = 4; i <= 11; i++) {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    while(N--) {
        int a;
        std::cin >> a;
        std::cout << d[a] << endl;
    }

    return 0;
}
