#include <string>

using namespace std;

int solution(string s)
{
    int answer = 1;

    for (int i = 0; i < 2 * s.length() - 1; i++) {
        int left = i / 2;
        int right = left + i % 2;

        while (left >= 0 && right < s.length()) {
            if (s[left] != s[right]) {
                break;
            }

            answer = max(answer, right - left + 1);
            left -= 1;
            right += 1;
        }
    }

    return answer;
}