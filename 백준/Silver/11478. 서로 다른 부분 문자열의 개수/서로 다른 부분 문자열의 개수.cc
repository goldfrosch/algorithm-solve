#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> CheckBoard;


int main() {
    // https://www.acmicpc.net/problem/11478
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    std::cin >> N;

    for (int i = 0; i < N.length(); i++) {
        for (int len = 1; len + i <= N.length(); len++) {
            CheckBoard.insert(N.substr(i, len));
        }
    }

    printf("%zu", CheckBoard.size());

    return 0;
}