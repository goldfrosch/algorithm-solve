#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int IsChangeJadenCase = true;

    for (const auto &item: s) {
        // 그냥 넘어가도 되는 케이스
        if (!IsChangeJadenCase) {
            if (item >= 'A' && item <= 'Z') {
                answer += (item + 32);
            } else {
                answer += item;
            }

            if (item == ' ') {
                IsChangeJadenCase = true;
            }

            continue;
        }

        if (item == ' ') {
            answer += item;
            continue;
        }

        IsChangeJadenCase = false;
        bool IsLower = item >= 'a' && item <= 'z';
        char Next = IsLower ? (item - 32) : item;
        answer += Next;
    }

    return answer;
}