#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int result[26] = { 0, };
    string S;

    std::cin >> S;

    for (int i = 0; i < S.length(); i++) {
        result[S[i] - 97] += 1;
    }

    for (int i = 0; i < 26; i++) {
        std::cout << result[i] << " ";
    }
}