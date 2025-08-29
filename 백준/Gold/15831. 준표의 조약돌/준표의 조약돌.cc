#include <iostream>

using namespace std;

int main()
{
    string s;
    int N, B, W;

    std::cin >> N >> B >> W;
    std::cin >> s;

    int st = 0, end = 0;
    int white = 0, black = 0;
    int max = 0;

    while(end < N) {
        if (black > B) {
            if (s[st] == 'B') {
                black -= 1;
            }
            if (s[st] == 'W') {
                white -= 1;
            }

            st += 1;

            continue;
        }

        if (s[end] == 'B') {
            black += 1;
        }
        if (s[end] == 'W') {
            white += 1;
        }

        end++;

        if (white >= W && black <= B) {
            max = max > end - st ? max : end - st;
        }
    }

    printf("%d", max);

    return 0;
}