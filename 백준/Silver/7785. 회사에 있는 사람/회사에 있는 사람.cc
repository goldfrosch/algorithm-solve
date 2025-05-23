#include <iostream>
#include <map>
#include <stack>

using namespace std;

map<string, bool> CheckBoard;


int main() {
    // https://www.acmicpc.net/problem/7785
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        string Name, Checked;
        std::cin >> Name >> Checked;

        CheckBoard[Name] = Checked == "enter";
    }

    stack<string> Result;

    for (const auto &item: CheckBoard) {
        if (CheckBoard[item.first]) {
            Result.push(item.first);
        }
    }

    while (!Result.empty()) {
        printf("%s\n", Result.top().c_str());
        Result.pop();
    }

    return 0;
}