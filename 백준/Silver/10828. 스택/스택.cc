#include <iostream>
#include <stack>
#include<string>
#include <algorithm>

using namespace std;

int main(void) {
    int num, count;
    string type;

    std::cin >> count;

    stack<int> stack;

    while (count != 0) {
        std::cin >> type;
        if (type == "push") {
            std::cin >> num;
            stack.push(num);
        }
        else if (type == "pop") {
            if (!stack.empty()) {
                std::cout << stack.top() << endl;
                stack.pop();
            }
            else {
                std::cout << -1 << endl;
            }
        }
        else if (type == "size") {
            std::cout << stack.size() << endl;
        }
        else if (type == "empty") {
            std::cout << (stack.empty() ? 1 : 0) << endl;
        }
        else if (type == "top") {
            std::cout << (stack.empty() ? -1 : stack.top()) << endl;
        }
        count--;
    }
    return 0;
}
