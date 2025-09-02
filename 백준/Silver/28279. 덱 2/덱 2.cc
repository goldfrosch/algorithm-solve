#include <iostream>
#include <deque>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    std::cin >> T;

    deque<int> Deque;

    for (int i = 0; i < T; i++) {
        int temp;
        std::cin >> temp;

        if (temp == 1 || temp == 2) {
            int temp2;
            std::cin >> temp2;

            if (temp == 1) {
                Deque.push_front(temp2);
            } else {
                Deque.push_back(temp2);
            }
        }

        else if (temp == 3) {
            if (Deque.empty()) {
                printf("-1\n");
                continue;
            }
            int temp2 = Deque.front();
            Deque.pop_front();
            printf("%d\n", temp2);
        }

        else if (temp == 4) {
            if (Deque.empty()) {
                printf("-1\n");
                continue;
            }
            int temp2 = Deque.back();
            Deque.pop_back();
            printf("%d\n", temp2);
        }

        else if (temp == 5) {
            printf("%zu\n", Deque.size());
        }

        else if (temp == 6) {
            printf("%d\n", Deque.empty());
        }

        else if (temp == 7 || temp == 8) {
            if (Deque.empty()) {
                printf("-1\n");
                continue;
            }

            if (temp == 7) {
                printf("%d\n", Deque.front());
            }

            if (temp == 8) {
                printf("%d\n", Deque.back());
            }
        }
    }


    return 0;
}