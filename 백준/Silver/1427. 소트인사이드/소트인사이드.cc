#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Compare(const char a, const char b) {
    return a > b;
}

int main() {
    // https://www.acmicpc.net/problem/30038
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    std::cin >> S;

    vector<char> CharList;

    for (int i = 0; i < S.length(); i++) {
        CharList.push_back(S[i]);
    }

    sort(CharList.begin(), CharList.end(), Compare);

    for (int i = 0; i < S.length(); i++) {
        printf("%c", CharList[i]);
    }

    return 0;
}