#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> queue;
    int count;

    cin >> count;

    for (int i = 0; i < count; i++) {
        string cmd;

        cin >> cmd;

        if (cmd == "push") {
            int temp;
            cin >> temp;

            queue.push(temp);
        } else if (cmd == "pop") {
            if (queue.empty()) {
                cout << "-1";
            } else {
                cout << queue.front();
                queue.pop();
            }
            cout << "\n";
        } else if (cmd == "size") {
            cout << queue.size() << "\n";
        } else if (cmd == "empty") {
            int a = queue.empty() ? 1 : 0;
            cout << a << "\n";
        } else if (cmd == "front") {
            if (queue.empty()) {
                cout << "-1";
            } else {
                cout << queue.front();
            }
            cout << "\n";
        } else if (cmd == "back") {
            if (queue.empty()) {
                cout << "-1";
            } else {
                cout << queue.back();
            }
            cout << "\n";
        }
    }

    return 0;
}
