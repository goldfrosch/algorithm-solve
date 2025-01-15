#include <iostream>
#include <regex>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/11140
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        string Value;
        std::cin >> Value;
        regex test("[a-z]*l[a-z]l[a-z]*");

        if (Value.find("lol") != string::npos) {
            printf("0\n");
        } else if (Value.find("lo") != string::npos || Value.find("ol") != string::npos || Value.find("ll") != string::npos || regex_match(Value, test)) {
            printf("1\n");
        } else if (Value.find("l") != string::npos || Value.find("o") != string::npos) {
            printf("2\n");
        } else {
            printf("3\n");
        }
    }
}