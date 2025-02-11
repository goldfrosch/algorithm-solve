#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;

    map<char, int> WolfMap;
    char Prev = 'w';  // 시작 문자를 'w'로 설정
    bool isFirstChar = true;

    // 첫 글자가 'w'가 아니면 잘못된 문자열
    if (N[0] != 'w') {
        cout << "0";
        return 0;
    }

    for (int i = 0; i < N.length(); i++) {
        char curr = N[i];
        
        // 현재 문자가 wolf 패턴에 없는 문자인 경우
        if (curr != 'w' && curr != 'o' && curr != 'l' && curr != 'f') {
            cout << "0";
            return 0;
        }

        // 이전 문자와 같은 경우
        if (curr == Prev) {
            WolfMap[curr]++;
        }
        // 다른 문자가 나온 경우
        else {
            // 올바른 순서인지 확인
            if ((Prev == 'w' && curr != 'o') || 
                (Prev == 'o' && curr != 'l') || 
                (Prev == 'l' && curr != 'f') || 
                (Prev == 'f' && curr != 'w')) {
                cout << "0";
                return 0;
            }

            // 'w'로 돌아올 때 이전 그룹의 카운트 검증
            if (curr == 'w') {
                if (WolfMap['w'] != WolfMap['o'] || 
                    WolfMap['o'] != WolfMap['l'] || 
                    WolfMap['l'] != WolfMap['f']) {
                    cout << "0";
                    return 0;
                }
                WolfMap.clear();  // 새로운 그룹 시작시 카운트 초기화
            }

            WolfMap[curr] = 1;  // 새로운 문자 카운트 시작
            Prev = curr;
        }
    }

    // 마지막 문자가 'f'가 아니면 잘못된 문자열
    if (Prev != 'f') {
        cout << "0";
        return 0;
    }

    // 최종 카운트 검증
    if (WolfMap['w'] != WolfMap['o'] || 
        WolfMap['o'] != WolfMap['l'] || 
        WolfMap['l'] != WolfMap['f']) {
        cout << "0";
        return 0;
    }

    cout << "1";
    return 0;
}