#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    int Val = 0, Max = 0;
    string Result;
    std::cin >> T;

    vector<pair<string, int>> MilitaryDate;

    for (int t = 0; t < T; t++) {
        string start, end;
        std::cin >> start >> end;

        MilitaryDate.emplace_back(start, -1);
        MilitaryDate.emplace_back(end, 1);
    }

    sort(MilitaryDate.begin(), MilitaryDate.end());

    for (const auto &item: MilitaryDate) {
        Val -= item.second;
        if (Max < Val) {
            Max = Val;
            Result = item.first;
        }
    }

    printf("%s", Result.c_str());

    return 0;
}