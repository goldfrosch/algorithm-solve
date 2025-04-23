#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/9498
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Score;
    std::cin >> Score;

    if (Score >= 90 && Score <= 100) {
        printf("A");
        return 0;
    }

    if (Score >= 80 && Score <= 89) {
        printf("B");
        return 0;
    }

    if (Score >= 70 && Score <= 79) {
        printf("C");
        return 0;
    }

    if (Score >= 60 && Score <= 69) {
        printf("D");
        return 0;
    }

    printf("F");


    return 0;
}