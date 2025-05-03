#include <iostream>

using namespace std;

int StudentClassInfo[1002][5];

int main() {
    // https://www.acmicpc.net/problem/1268
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 5; j++){
            std::cin >> StudentClassInfo[i][j];
        }
    }

    int MaxIndex = 1;
    int MaxValue = 0;
    // 1번 부터 N번 학생까지 반복해서 값을 계산함
    for (int i = 1; i <= N; i++) {
        int Temp = 0;
        // 1학년부터 5학년까지 비교해보기
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;

            for (int k = 0; k < 5; k++){
                // i번째 학생을 제외한 나머지 반에 대한 값을 조사
                if (StudentClassInfo[i][k] == StudentClassInfo[j][k]) {
                    Temp += 1;
                    break;
                }
            }
        }

        if (MaxValue < Temp) {
            MaxIndex = i;
            MaxValue = Temp;
        }
    }

    printf("%d", MaxIndex);

    return 0;
}