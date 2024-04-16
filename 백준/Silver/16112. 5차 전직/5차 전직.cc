#include <iostream>
#include <vector>
#include <algorithm>

#define vl long long int

using namespace std;


int N, K;
vector<int> exp;

int main() {
    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        exp.push_back(temp);
    }

    sort(exp.begin(), exp.end());

    long long int result = 0;

    for (int i = 0; i < N; i++) {
        const auto v = i < K ? i : K;
        result += (vl)exp.at(i) * (vl)v;
    }

    std::cout << result;

    return 0;
}