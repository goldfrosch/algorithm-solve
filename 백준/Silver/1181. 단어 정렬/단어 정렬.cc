#include <iostream>
#include <set>

using namespace std;

struct compare {
    bool operator() (const string& a, const string& b) const {
        if (a.length() != b.length()) {
            return a.length() < b.length();
        }

        return a < b;
    }
};

int main() {
    // https://www.acmicpc.net/problem/1026
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string, compare> List;

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        string Temp;
        std::cin >> Temp;

        List.insert(Temp);
    }

    for (const auto &item: List) {
        printf("%s\n", item.c_str());
    }

    return 0;
}