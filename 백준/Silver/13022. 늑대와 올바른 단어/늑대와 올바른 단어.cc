#include <iostream>
#include <map>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/7432
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    std::cin >> N;

    // wolf 관련 글자 정보 저장하는 Map 하나
    // 다음 글자로 넘어갈 때 Map에서 이전 글자 정보 초기화
    // 다음 글자로 넘어갈 때 그 다음 글자가 순서가 틀리다면 그대로 종료 (틀림)

    map<char, int> WolfMap;
    char Prev = 'f';
    for (int i = 0; i < N.length(); i++) {
        // 혹시 모를 다른 글자에 대한 예외 처리
        if (N[i] != 'w' && N[i] != 'o' && N[i] != 'l' && N[i] != 'f') {
            printf("0");
            return 0;
        }

        if (Prev != N[i]) {
            if ((Prev == 'w' && N[i] != 'o') || Prev == 'o' && N[i] != 'l'
                || Prev == 'l' && N[i] != 'f' || Prev == 'f' && N[i] != 'w') {
                printf("0");
                return 0;
            }

            // 하나의 wolf 쌍이 완성되고 초기화 단계로 넘어가는 경우
            if (N[i] == 'w') {
                if (WolfMap['w'] != WolfMap['o'] || WolfMap['o'] != WolfMap['l'] || WolfMap['l'] != WolfMap['f']) {
                    printf("0");
                    return 0;
                }
                WolfMap.clear();
            }
            WolfMap[N[i]] == 1;
            Prev = N[i];
        } else {
            WolfMap[Prev] += 1;
        }
    }

    if (Prev != 'f') {
        printf("0");
        return 0;
    }

    const bool Answer =
        WolfMap['w'] == WolfMap['o']
        && WolfMap['o'] == WolfMap['l']
        && WolfMap['l'] == WolfMap['f'];

    printf("%d", Answer);
    return 0;
}