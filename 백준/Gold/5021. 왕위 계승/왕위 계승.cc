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
    
    map<string, vector<string>> children;  // 부모 -> 자식들
    map<string, int> indegree;            // 진입차수
    map<string, vector<string>> parents;   // 자식 -> 부모들
    map<string, double> blood;            // 혈통치
    
    // 입력 처리
    for(int i = 0; i < N; i++) {
        string child, parent1, parent2;
        cin >> child >> parent1 >> parent2;
        
        children[parent1].push_back(child);
        children[parent2].push_back(child);
        parents[child].push_back(parent1);
        parents[child].push_back(parent2);
        indegree[child] += 2;  // 부모가 2명이므로 진입차수 2 증가
        
        // 모든 등장인물의 혈통치를 0으로 초기화
        blood[child] = 0;
        blood[parent1] = 0;
        blood[parent2] = 0;
    }
    
    // 왕의 혈통치는 1
    blood[king] = 1.0;
    
    // 위상정렬을 위한 큐
    queue<string> q;
    
    // 진입차수가 0인 정점(왕과 부모가 없는 사람들)을 큐에 넣음
    for(auto& p : blood) {
        if(indegree[p.first] == 0) {
            q.push(p.first);
        }
    }
    
    // 위상정렬 수행
    while(!q.empty()) {
        string current = q.front();
        q.pop();
        
        // current의 모든 자식들에 대해
        for(string& child : children[current]) {
            // 자식의 혈통치에 current의 혈통치/2를 더함
            blood[child] += blood[current] / 2.0;
            
            // 진입차수 감소
            indegree[child]--;
            
            // 진입차수가 0이 되면 큐에 추가
            if(indegree[child] == 0) {
                q.push(child);
            }
        }
    }
    
    // 왕위 계승 후보들 중 혈통치가 가장 높은 사람 찾기
    string answer;
    double maxBlood = -1;
    
    for(int i = 0; i < M; i++) {
        string candidate;
        cin >> candidate;
        
        if(blood[candidate] > maxBlood) {
            maxBlood = blood[candidate];
            answer = candidate;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}