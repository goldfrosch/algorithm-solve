#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int N, M;
    string king;
    cin >> N >> M >> king;

    map<string, vector<string>> children;
    map<string, int> indegree;
    map<string, vector<string>> parents;
    map<string, double> blood;

    // 왕의 혈통치 초기화
    blood[king] = 1.0;

    // 가계도 입력 처리
    for(int i = 0; i < N; i++) {
        string child, parent1, parent2;
        cin >> child >> parent1 >> parent2;

        children[parent1].push_back(child);
        children[parent2].push_back(child);
        parents[child].push_back(parent1);
        parents[child].push_back(parent2);
        indegree[child] += 2;

        // 등장하는 모든 사람들 초기화
        blood[child] = 0;
        blood[parent1] = 0;
        blood[parent2] = 0;
    }

    // 후보자들 미리 입력받아서 초기화
    vector<string> candidates(M);
    for(int i = 0; i < M; i++) {
        cin >> candidates[i];
        // 아직 blood에 없는 후보자라면 0으로 초기화
        blood[candidates[i]] = 0;
    }

    // 다시 왕의 혈통치는 1로 설정 (이전 초기화에서 0이 되었을 수 있음)
    blood[king] = 1.0;

    queue<string> q;
    for(auto& p : blood) {
        if(indegree[p.first] == 0) {
            q.push(p.first);
        }
    }

    while(!q.empty()) {
        string current = q.front();
        q.pop();

        for(string& child : children[current]) {
            blood[child] += blood[current] / 2.0;
            indegree[child]--;

            if(indegree[child] == 0) {
                q.push(child);
            }
        }
    }

    // 미리 입력받은 후보자들 중에서 최대값 찾기
    string answer = candidates[0];
    double maxBlood = blood[candidates[0]];

    for(int i = 1; i < M; i++) {
        if(blood[candidates[i]] > maxBlood) {
            maxBlood = blood[candidates[i]];
            answer = candidates[i];
        }
    }

    cout << answer << endl;

    return 0;
}