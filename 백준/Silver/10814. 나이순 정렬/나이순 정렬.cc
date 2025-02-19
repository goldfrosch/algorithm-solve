#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
    int Age{};
    string Name;
    int Index{};
};

bool Compare(const Data& a, const Data& b) {
    if (a.Age != b.Age) {
        return a.Age < b.Age;
    }

    return a.Index < b.Index;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    vector<Data> List;
    for (int i = 0; i < N; i++) {
        int Age;
        string Name;

        std::cin >> Age >> Name;
        Data NewData;
        NewData.Age = Age;
        NewData.Name = Name;
        NewData.Index = i;

        List.push_back(NewData);
    }

    sort(List.begin(), List.end(), Compare);

    for (const auto &item: List) {
        printf("%d %s\n", item.Age, item.Name.c_str());
    }

    return 0;
}