#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> List;

int main() {
    // https://www.acmicpc.net/problem/11399
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int Temp;
        std::cin >> Temp;
        List.push_back(Temp);
    }

    sort(List.begin(), List.end());

    int Result = List[0];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            Result += List[j];
        }
    }

    printf("%d", Result);

    return 0;
}