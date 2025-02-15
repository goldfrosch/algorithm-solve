#include <iostream>
#include <map>

using namespace std;

map<char, char> Parse;

int main() {
    // https://www.acmicpc.net/problem/9625
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Parse['@'] = 'a';
    Parse['['] = 'c';
    Parse['!'] = 'i';
    Parse[';'] = 'j';
    Parse['^'] = 'n';
    Parse['0'] = 'o';
    Parse['7'] = 't';

    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        string Temp;
        std::cin >> Temp;

        string NewValue;
        int Count = 0;
        for (int j = 0; j < Temp.length(); j++) {
            // 우선 임시 용 으로 글자 하나를 바로 추가한다.
            // 추가한 글씨가 Parse할 데이터인 경우
            if (Parse.find(Temp[j]) != Parse.end()) {
                // 카운트를 하나 추가하고 기존 값을 초기화한다.
                Count += 1;
                NewValue += Parse[Temp[j]];
                continue;
            }

            if (Temp[j] == '\\') {
                if (j + 1 < Temp.length() && Temp[j + 1] == '\'') {
                    j += 1;
                    Count += 1;
                    NewValue += 'v';
                    continue;
                }
                if (j + 2 < Temp.length() && Temp[j + 1] == '\\' && Temp[j + 2] == '\'') {
                    j += 2;
                    Count += 1;
                    NewValue += 'w';
                    continue;
                }
            }

            NewValue += Temp[j];
        }

        if ((double) Count >= (double) NewValue.length() / 2) {
            printf("I don't understand\n");
        } else {
            printf("%s\n", NewValue.c_str());
        }
    }

    return 0;
}