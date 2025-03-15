#include <iostream>
#include <map>
#include <set>

using namespace std;

struct Compare {
    bool operator() (const string &a, const string &b) const{
        return a < b;
    }
};

map<string, int> CountData;
set<string, Compare> Extensions;

int main() {
    // https://www.acmicpc.net/problem/28432
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        string Temp;
        std::cin >> Temp;

        auto Count = Temp.find('.');
        if (Count != string::npos) {
            string Result = Temp.substr(Count + 1, Temp.length() - 1);

            Extensions.insert(Result);
            CountData[Result] += 1;
        }
    }

    for (const auto &item: Extensions) {
        printf("%s %d\n", item.c_str(), CountData[item]);
    }

    return 0;
}