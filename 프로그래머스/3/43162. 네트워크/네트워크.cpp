#include <vector>
#include <stack>

using namespace std;

bool IsVisited[200];
int answer = 0;

int solution(int n, vector<vector<int>> computers) {

    for (int i = 0; i < n; i++) {
        if (!IsVisited[i]) {
            stack<int> Nodes;
            Nodes.push(i);
            answer += 1;
            IsVisited[i] = true;

            while (!Nodes.empty()) {
                int top = Nodes.top();
                Nodes.pop();

                for (int j = 0; j < computers[top].size(); j++) {
                    if (computers[top][j] == 1) {
                        if (!IsVisited[j]) {
                            Nodes.push(j);
                            IsVisited[j] = true;
                        }
                    }
                }
            }
        }
    }

    return answer;
}