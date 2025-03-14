#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    // https://www.acmicpc.net/problem/1475
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    std::cin >> S;

    map<char, int> ValueMap;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '9') {
            ValueMap['6'] += 1;
        } else {
            ValueMap[S[i]] += 1;
        }
    }

    if (ValueMap['6'] % 2 == 1) {
        ValueMap['6'] += 1;
    }

    ValueMap['6'] /= 2;

    int MaxValue = 0;

    for (auto value_map : ValueMap) {
        MaxValue = max(value_map.second, MaxValue);
    }

    printf("%d", MaxValue);

    return 0;
}