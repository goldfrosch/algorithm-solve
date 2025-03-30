#include <iostream>
#include <queue>

using namespace std;

queue<int> List;

int main() {
    // https://www.acmicpc.net/problem/11866
    int N, M;
    std::cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        List.push(i);
    }

    printf("<");

    while (!List.empty()) {
        for (int i = 0; i < M - 1; i++) {
            int Temp = List.front();
            List.pop();
            List.push(Temp);
        }

        if (List.size() == 1) {
            printf("%d", List.front());
        } else {
            printf("%d, ", List.front());
        }

        List.pop();
    }

    printf(">");

    return 0;
}