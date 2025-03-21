#include <iostream>
#include <algorithm>

using namespace std;

string DP[10002];

string Sum(string a, string b) {
    string Result = "";
    int CarryNum = 0;

    while (!a.empty() || !b.empty()) {
        int NumA = 0, NumB = 0;

        // a에 남은 문자열 있을 때
        if (!a.empty()) {
            // 마지막 문자열 가져오고, 더 계산할 필요는 없으니
            NumA = a.back() - '0';
            // 뒤에를 제거해준다.
            a.pop_back();
        }
        if (!b.empty()) {
            NumB = b.back() - '0';
            b.pop_back();
        }

        int CurrentSum = NumA + NumB + CarryNum;
        // 각 숫자의 가장 뒷자리만 더해준다.
        Result += to_string(CurrentSum % 10);
        // 두 숫자의 덧셈으로 10이 넘어가는 경우는 1을 다음 자리에 추가해야 하니
        // 새롭게 값 할당해주기
        CarryNum = CurrentSum / 10;
    }

    // 마지막 문자열까지 비교했음에도 CarryNum이 1이라는 것은 새로운 자리수가 추가됨을 의미
    if (CarryNum == 1) {
        Result += "1";
    }

    reverse(Result.begin(), Result.end());

    return Result;
}

int main() {
    // https://www.acmicpc.net/problem/10826
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    DP[0] = "0";
    DP[1] = "1";

    for (int i = 2; i <= N; i++) {
        DP[i] = Sum(DP[i - 1], DP[i - 2]);
    }

    printf("%s", DP[N].c_str());

    return 0;
}