#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string PocketMonList[100003];
map<string, int> PocketMonListToMap;

int main() {
    // https://www.acmicpc.net/problem/1620
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string Temp;
        std::cin >> Temp;
        PocketMonList[i] = Temp;
        PocketMonListToMap[Temp] = i;
    }

    for (int i = 0; i < M; i++) {
        string Question;
        std::cin >> Question;

        if (atoi(Question.c_str()) == 0) {
            printf("%d", PocketMonListToMap[Question]);
        } else {
            printf("%s", PocketMonList[stoi(Question)].c_str());
        }

        printf("\n");
    }


    return 0;
}