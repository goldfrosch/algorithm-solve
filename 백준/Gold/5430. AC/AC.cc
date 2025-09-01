#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

void Parsing(const string& origin, deque<int>& values) {
    // 배열을 감싼 대괄호는 제거
    string ResultNum;

    for (const auto &item: origin) {
        if (item >= '0' && item <= '9') {
            ResultNum += item;
            continue;
        }

        if (!ResultNum.empty()) {
            values.push_back(std::stoi(ResultNum));
            ResultNum = "";
        }
    }
}

void Print(const int& count, const deque<int>& values) {
    if (count <= 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (int j = 0; j < count - 1; j++) {
        printf("%d,", values[j]);
    }
    printf("%d]\n", values[count - 1]);
}

int main()
{
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        string p;
        int n;
        string test;
        std::cin >> p >> n >> test;

        deque<int> value;
        Parsing(test, value);

        bool ReverseFlag = false;
        bool IsEnd = false;

        for (const auto &item: p) {
            if (item == 'R') {
                ReverseFlag = !ReverseFlag;
            }

            if (item == 'D') {
                if (n == 0) {
                    printf("error\n");
                    IsEnd = true;
                    break;
                }

                ReverseFlag ? value.pop_back() : value.pop_front();
                n -= 1;
            }
        }

        if (IsEnd) {
            continue;
        }

        if (ReverseFlag) {
            reverse(value.begin(), value.end());
        }

        Print(n, value);
    }

    return 0;
}