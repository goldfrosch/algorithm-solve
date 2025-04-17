#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/29700
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i <= N; i++) {
        stack<string> Stack;
        string Temp;

        getline(cin, Temp);

        string TempData;
        for (int j = 0; j < Temp.length(); j++) {
            if (Temp[j] == ' ') {
                Stack.push(TempData);
                TempData = "";
            } else {
                TempData += Temp[j];
            }
        }
        Stack.push(TempData);

        if (i != 0) {
            printf("Case #%d: ", i);
            while (!Stack.empty()) {
                string Data = Stack.top();
                printf("%s ", Data.c_str());
                Stack.pop();
            }
            printf("\n");
        }
    }

    return 0;
}