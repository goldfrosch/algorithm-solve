#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    string Winner = N % 2 == 0 ? "CY" : "SK";

    printf("%s", Winner.c_str());

    return 0;
}