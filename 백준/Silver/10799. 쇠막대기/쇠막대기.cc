#include <iostream>
#include <vector>

using namespace std;

int main() {
    string ironStick;
    vector<char> stickCmd = {};

    int result = 0;

    std::cin >> ironStick;

    for (int i = 0; i < ironStick.size();i ++) {
        auto cmd = ironStick[i];
        if (cmd == '(') {
            stickCmd.push_back(cmd);
        } else if (cmd == ')') {
            stickCmd.pop_back();

            if (ironStick[i - 1] == '(') {
                result += static_cast<int>(stickCmd.size());
            } else if (ironStick[i - 1] == ')') {
                result += 1;
            }
        }
    }

    std::cout << result;

    return 0;
}
