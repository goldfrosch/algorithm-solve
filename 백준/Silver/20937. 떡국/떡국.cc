#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> list;

int main() {

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        list[a] += 1;
    }

    int Result = 0;
    while (!list.empty()) {
        vector<int> RemoveList;

        for (auto pair : list) {
            list[pair.first] -= 1;
            if (list[pair.first] == 0) {
                RemoveList.push_back(pair.first);
            }
        }

        for (int Remove : RemoveList) {
            list.erase(Remove);
        }

        Result += 1;
    }

    printf("%d", Result);

    return 0;
}