#include <iostream>
#include <stack>
#include <vector>
#include<string>
#include <algorithm>

using namespace std;

int getResult(string vps) {
    string data;
    bool result;
    stack<char> vpsInput;

    if (vps == ".") {
        return 0;
    }

    while (!vps.empty()) {
        if (vps.back() == '(' || vps.back() == '[') {
            if (vpsInput.empty()) {
                break;
            }
            else {
                if (vpsInput.top() == ')' && vps.back() != '(') {
                    break;
                }
                if (vpsInput.top() == ']' && vps.back() != '[') {
                    break;
                }
                vpsInput.pop();
                vps.pop_back();
            }
        }
        else if (vps.back() == ')' || vps.back() == ']') {
            vpsInput.push(vps.back());
            vps.pop_back();
        }
        else {
            vps.pop_back();
        }
    }
    if (vpsInput.empty() && vps.empty()) {
        std::cout << "yes" << endl;
    }
    else {
        std::cout << "no" << endl;
    }

    getline(cin, data);
    getResult(data);

    return 0;
}

int main(void) {
    string vps;
    getline(cin, vps);

    getResult(vps);
    return 0;
}
