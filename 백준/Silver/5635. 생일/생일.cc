#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
    string Name;
    int Day{};
    int Month{};
    int Year{};
};

bool Compare(const Data& a, const Data& b) {
    if (a.Year != b.Year) {
        return a.Year > b.Year;
    }

    if (a.Month != b.Month) {
        return a.Month > b.Month;
    }

    return a.Day > b.Day;
}

int main() {
    // https://www.acmicpc.net/problem/5635
    int N;
    std::cin >> N;

    Data DataList[101];

    for (int i = 0; i < N; i++) {
        Data NewData;
        std::cin >> NewData.Name;
        std::cin >> NewData.Day;
        std::cin >> NewData.Month;
        std::cin >> NewData.Year;

        DataList[i] = NewData;
    }

    sort(DataList, DataList + N, Compare);

    printf("%s\n", DataList[0].Name.c_str());
    printf("%s", DataList[N - 1].Name.c_str());

    return 0;
}