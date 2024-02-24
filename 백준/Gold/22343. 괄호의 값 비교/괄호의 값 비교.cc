#include <iostream>

using namespace std;

int resultBracket(string bracket) {
    int result = 0;
    int temp = 1;

    for (int i = 0; i < bracket.length(); i++) {
        if (bracket[i] == '(') {
            temp *= 2;
        } else {
            if (bracket[i - 1] == '(') {
                temp /= 2;
                result += temp;
            } else {
                temp /= 2;
            }
        }
    }

    return result;
}

int main() {
    string bracket;
    int a, b;
    int N;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> bracket;
        a = resultBracket(bracket);

        std::cin >> bracket;
        b = resultBracket(bracket);

        if (a > b) {
            std::cout << ">\n";
        } else if (a < b) {
            std::cout << "<\n";
        } else {
            std::cout << "=\n";
        }
    }
    return 0;
}
