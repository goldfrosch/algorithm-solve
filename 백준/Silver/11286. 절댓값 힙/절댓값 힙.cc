#include <iostream>
#include <queue>

using namespace std;

struct AbsCompare {
    bool operator()(const int& a, const int& b) {
        int CompareA = abs(a);
        int CompareB = abs(b);
        if (CompareA == CompareB) {
            return a > b;
        }

        return CompareA > CompareB;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, AbsCompare> Queue;

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int Temp;
        std::cin >> Temp;

        if (Temp == 0) {
            if (Queue.empty()) {
                printf("0\n");
            } else {
                printf("%d\n", Queue.top());
                Queue.pop();
            }
        } else {
            Queue.push(Temp);
        }
    }

    return 0;
}