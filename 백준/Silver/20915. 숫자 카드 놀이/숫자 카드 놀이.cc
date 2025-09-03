#include <iostream>
#include <map>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        map<int, int> cache;

        string temp;
        string tempA, tempB;
        std::cin >> temp;

        for (int i = 0; i < temp.length(); i++) {
            int keyInt = temp[i] - 48 == 6 ? 9 : temp[i] - 48;
            cache[keyInt] += 1;
        }

        for (int i = 9; i >= 0; i--) {
            const char keyChar = (char)(i + 48);
            for (int j = 0; j < cache[i]; j++) {
                if (tempA.empty() || tempB.empty()) {
                    if (tempA.empty()) {
                        tempA = keyChar;
                    } else {
                        tempB = keyChar;
                    }
                } else {
                    if (stoi(tempA) > stoi(tempB)) {
                        tempB += keyChar;
                    } else {
                        tempA += keyChar;
                    }
                }
            }
        }

        long long result = stoll(tempA) * stoll(tempB);

        printf("%lld\n", result);
    }

    return 0;
}