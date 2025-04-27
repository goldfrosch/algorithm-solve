#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/9322
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int Case;
        std::cin >> Case;

        string SecurityKey[Case];
        int Position[Case];

        // 암호용 단어 입력
        for (int j = 0; j < Case; j++) {
            std::cin >> SecurityKey[j];
        }

        // 암호 순서를 위한 암호용 단어 다시 입력
        for (int j = 0; j < Case; j++) {
            string Temp;
            std::cin >> Temp;

            // 입력한 문자가 어디에 있는지 분석 한다.
            for (int k = 0; k < Case; k++) {
                if (Temp == SecurityKey[k]) {
                    Position[k] = j;
                }
            }
        }

        // 정답용 단어 입력
        string ResultData[Case];
        for (int j = 0; j < Case; j++) {
            std::cin >> ResultData[j];
        }

        // 단어를 기반 으로 위치 찾아서 넣기

        for (int j = 0; j < Case; j++) {
            printf("%s ", ResultData[Position[j]].c_str());
        }

        printf("\n");
    }

    return 0;
}