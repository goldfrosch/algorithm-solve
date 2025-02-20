#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    deque<int> Queue;
    for (int i = 0; i < N; i++) {
        string Cmd;
        std::cin >> Cmd;

        if (Cmd == "push") {
            int Temp;
            std::cin >> Temp;

            Queue.push_back(Temp);
        }

        if (Cmd == "pop") {
            if (Queue.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", Queue.front());
                Queue.pop_front();
            }
        }

        if (Cmd == "front") {
            if (Queue.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", Queue.front());
            }
        }

        if (Cmd == "back") {
            if (Queue.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", Queue.back());
            }
        }

        if (Cmd == "size") {
            printf("%zu\n", Queue.size());
        }

        if (Cmd == "empty") {
            printf("%d\n", Queue.empty());
        }
    }

    return 0;
}