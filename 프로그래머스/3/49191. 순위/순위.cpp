#include <string>
#include <vector>

using namespace std;

int MatchResult[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            MatchResult[i][j] = 0;
        }
    }

    for (const auto &item: results) {
        MatchResult[item[0]][item[1]] = 1;
        MatchResult[item[1]][item[0]] = -1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            for (int k = 1; k <= n; k++) {
                if (i == k || j == k) continue;

                if (MatchResult[i][j] != 0 && MatchResult[j][k] == MatchResult[i][j]) {
                    MatchResult[i][k] = MatchResult[i][j];
                    MatchResult[k][i] = -1 * MatchResult[i][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (const auto &j: MatchResult[i]) {
            temp += (j == 0 ? 0 : 1);
        }

        if (temp == n - 1) answer += 1;
    }

    return answer;
}