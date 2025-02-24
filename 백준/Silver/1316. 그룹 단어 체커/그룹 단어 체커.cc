#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    int Result = 0;
    for (int i = 0; i < N; i++) {
        map<char, int> Case;

        string Temp;
        std::cin >> Temp;

        bool IsCheck = true;
        char PrevChar = Temp[0];
        Case[PrevChar] = 1;
        for (int j = 1; j < Temp.length(); j++) {
            if (PrevChar != Temp[j] && Case[Temp[j]] > 0) {
                IsCheck = false;
                break;
            }
            Case[Temp[j]] += 1;
            PrevChar = Temp[j];
        }

        if (IsCheck) {
            Result += 1;
        }
    }

    printf("%d", Result);

    return 0;
}