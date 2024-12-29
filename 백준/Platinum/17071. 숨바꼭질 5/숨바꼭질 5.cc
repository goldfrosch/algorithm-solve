#include <iostream>
#include <queue>
using namespace std;

bool visited[500001][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    if (N == K) {
        cout << 0;
        return 0;
    }
    
    queue<int> q;
    q.push(N);
    visited[N][0] = true;
    
    int time = 0;
    while (!q.empty() && K <= 500000) {
        K += time;  // 동생의 현재 위치
        
        // 범위를 벗어나면 종료
        if (K > 500000) {
            break;
        }
        
        // 현재 시간의 모든 위치에서 동생을 찾을 수 있는지 확인
        if (visited[K][time % 2]) {
            cout << time;
            return 0;
        }
        
        int size = q.size();
        while (size--) {
            int curr = q.front();
            q.pop();
            
            for (int next : {curr-1, curr+1, curr*2}) {
                if (next < 0 || next > 500000) continue;
                if (visited[next][(time + 1) % 2]) continue;
                
                visited[next][(time + 1) % 2] = true;
                q.push(next);
            }
        }
        
        time++;
    }
    
    cout << -1;
    return 0;
}