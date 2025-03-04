#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    std::cin >> N;

    bool IsStart = false;
    string TempNum;
    int Result = 0;
    char PrevCalc = N[0] == '-' ? '-' : '+';
    for (int i = 0; i < N.length(); i++) {
        if (N[i] == '-' || N[i] == '+') {
            // 첫 시작 시만 별도의 계산식 없이 값을 바로 더해줌
            if (!IsStart) {
               Result = stoi(TempNum);
               IsStart = true;
            } else {
                // 여기서부터는 케이스가 조금 달라짐
                // 앞에 -가 있었냐를 먼저 검증해야함.
                if (PrevCalc == '-') {
                    Result -= abs(stoi(TempNum));
                } else {
                    Result += abs(stoi(TempNum));
                }
            }
            TempNum = "";

            if (N[i] == '-') {
                PrevCalc = '-';
            }

        } else {
            TempNum += N[i];
        }
    }

    if (PrevCalc == '-') {
        Result -= abs(stoi(TempNum));
    } else {
        Result += abs(stoi(TempNum));
    }

    printf("%d", Result);

    return 0;
}