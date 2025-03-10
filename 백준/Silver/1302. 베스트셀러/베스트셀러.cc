#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }

    return a < b;
}

int main() {
    // https://www.acmicpc.net/problem/1302
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    map<string, int> Books;

    for (int i = 0; i < N; i++) {
        string Temp;
        std::cin >> Temp;
        Books[Temp] += 1;
    }

    vector<pair<string, int>> BookData(Books.begin(), Books.end());

    sort(BookData.begin(), BookData.end(), Compare);

    printf("%s", BookData[0].first.c_str());

    return 0;
}