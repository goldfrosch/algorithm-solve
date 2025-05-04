#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int>> List;

bool Compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second > b.second;
}

int main() {
    // https://www.acmicpc.net/problem/2535
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int TempCountry, TempNum, TempScore;

        std::cin >> TempCountry >> TempNum >> TempScore;

        List.push_back({{TempCountry, TempNum}, TempScore});
    }

    sort(List.begin(), List.end(), Compare);

    int CountryCheck = 0;

    printf("%d %d\n", List[0].first.first, List[0].first.second);
    printf("%d %d\n", List[1].first.first, List[1].first.second);

    if (List[0].first.first != List[1].first.first) {
        printf("%d %d\n", List[2].first.first, List[2].first.second);
        return 0;
    }

    CountryCheck = List[0].first.first;
    for (int i = 2; i < N; i++) {
        if (List[i].first.first != CountryCheck) {
            printf("%d %d\n", List[i].first.first, List[i].first.second);
            return 0;
        }
    }

    return 0;
}