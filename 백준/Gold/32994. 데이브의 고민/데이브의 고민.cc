#include <iostream>
#include <vector>
using namespace std;

void solve_fish_farm(int N, int M) {
    // 기본 패턴 정의 (5x5 패턴)
    int pattern[5][5] = {
        {1, 2, 3, 4, 5},
        {3, 4, 5, 1, 2},
        {5, 1, 2, 3, 4},
        {2, 3, 4, 5, 1},
        {4, 5, 1, 2, 3}
    };
    
    // 각 위치에 패턴 적용하여 출력
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << pattern[i % 5][j % 5];
            if(j < M-1) cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    solve_fish_farm(N, M);
    
    return 0;
}