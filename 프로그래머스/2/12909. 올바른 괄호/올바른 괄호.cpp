#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> Stack;

    for (const auto &item: s) {
        if (Stack.empty()) {
            Stack.push(item);
            continue;
        }

        if (Stack.top() == '(' && item == ')') {
            Stack.pop();
        } else {
            Stack.push(item);
        }
    }

    return Stack.empty();
}