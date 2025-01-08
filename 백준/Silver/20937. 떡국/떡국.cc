#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> list;

int main() {

    int N;
    std::cin >> N;

    int Result = 0;

    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        list[a] += 1;
        Result = max(Result, list[a]);
    }

    printf("%d", Result);

    return 0;
}