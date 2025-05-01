#include <iostream>
#include <set>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/25757
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    char M;
    std::cin >> N >> M;

    set<string> JoinedPlayer;
    for (int i = 0; i < N; i++) {
        string Temp;
        std::cin >> Temp;

        JoinedPlayer.insert(Temp);
    }

    int Player = JoinedPlayer.size();

    if (M == 'Y') {
        printf("%d", Player);
        return 0;
    }

    if (M == 'F') {
        printf("%d", Player / 2);
        return 0;
    }

    printf("%d", Player / 3);
    return 0;
}