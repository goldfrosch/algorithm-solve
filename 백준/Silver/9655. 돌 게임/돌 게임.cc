#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    int Result = 0;
    Result += N / 3;
    Result += N % 3;

    string Winner = Result % 2 == 0 ? "CY" : "SK";

    printf("%s", Winner.c_str());

    return 0;
}