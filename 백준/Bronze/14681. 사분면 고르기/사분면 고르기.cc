#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/14681
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y;
    std::cin >> X >> Y;

    if (X > 0 && Y > 0) {
        printf("1");
        return 0;
    }

    if (X < 0 && Y > 0) {
        printf("2");
        return 0;
    }

    if (X < 0 && Y < 0) {
        printf("3");
        return 0;
    }

    if (X > 0 && Y < 0) {
        printf("4");
        return 0;
    }

    return 0;
}