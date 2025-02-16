#include <iostream>
#include <map>

using namespace std;

map<char, char> Parse;

int main() {
    // https://www.acmicpc.net/problem/9625
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    std::cin >> N >> D;

    int Result = 0;
    for (int i = 1; i <= N; i++) {
        string Temp = to_string(i);

        for (int j = 0; j < Temp.length(); j++) {
            if (Temp[j] - '0' == D) {
                Result += 1;
            }
        }
    }

    printf("%d", Result);

    return 0;
}