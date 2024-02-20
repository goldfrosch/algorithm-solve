#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> deque;
    int n;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        string a;
        std::cin >> a;

        if (a == "push_back") {
            int b;
            std::cin >> b;
            deque.push_back(b);
        } else if (a == "push_front") {
            int b;
            std::cin >> b;
            deque.push_front(b);
        } else if (a == "pop_front") {
            if (deque.empty()) {
                std::cout << -1 << "\n";
            } else {
                std::cout << deque.front() << "\n";
                deque.pop_front();
            }
        } else if (a == "pop_back") {
            if (deque.empty()) {
                std::cout << -1 << "\n";
            } else {
                std::cout << deque.back() << "\n";
                deque.pop_back();
            }
        } else if (a == "size") {
            std::cout << deque.size() << "\n";
        } else if (a == "empty") {
            auto isEmpty = deque.empty() ? 1 : 0;
            std::cout << isEmpty << "\n";
        } else if (a == "front") {
            if (deque.empty()) {
                std::cout << -1 << "\n";
            } else {
                std::cout << deque.front() << "\n";
            }
        } else if (a == "back") {
            if (deque.empty()) {
                std::cout << -1 << "\n";
            } else {
                std::cout << deque.back() << "\n";
            }
        }
    }

    return 0;
}
