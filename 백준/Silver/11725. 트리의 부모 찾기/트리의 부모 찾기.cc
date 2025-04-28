#include <iostream>
#include <vector>

using namespace std;


int Array[100001];
// DFS 방문 여부 확인
bool IsVisited[100001];
// 각 그래프 노드 간선 저장할 정보 2중 배열
vector<int> Data[100001];

void DFS(int K) {
    IsVisited[K] = true;

    for (int i = 0; i < Data[K].size(); i++) {
        int Next = Data[K][i];

        // 방문하지 않은 간선이면 계속 깊이 들어가서 확인함
        if (!IsVisited[Next]) {
            // 깊이 들어가기 전에 부모 노드가 어떤 건지 체크해서 값 넣어준다.
            Array[Next] = K;
            DFS(Next);
        }
    }
}

int main() {
    // https://www.acmicpc.net/problem/11725
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 1; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;
        // 각 그래프 노드에 서로 간의 노드 전달
        Data[X].push_back(Y);
        Data[Y].push_back(X);
    }

    DFS(1);

    for (int i = 2; i <= N; i++) {
        printf("%d\n", Array[i]);
    }

    return 0;
}