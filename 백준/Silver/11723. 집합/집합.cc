#include <iostream>
#include <set>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1012
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    std::cin >> M;

    set<int> Data;

    for (int i = 0; i < M; i++) {
        string Cmd;
        std::cin >> Cmd;

        if (Cmd == "add") {
            int Temp;
            std::cin >> Temp;
            Data.insert(Temp);
        }
        if (Cmd == "remove") {
            int Temp;
            std::cin >> Temp;
            Data.erase(Temp);
        }
        if (Cmd == "check") {
            int Temp;
            std::cin >> Temp;
            printf("%d\n", Data.contains(Temp));
        }
        if (Cmd == "toggle") {
            int Temp;
            std::cin >> Temp;
            if (Data.contains(Temp)) {
                Data.erase(Temp);
            } else {
                Data.insert(Temp);
            }
        }
        if (Cmd == "all") {
            for (int a = 1; a <= 20; a++) {
                Data.insert(a);
            }
        }
        if (Cmd == "empty") {
            Data.clear();
        }
    }

    return 0;
}