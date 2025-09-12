#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
// 정점, 간선, 길이 Input 값들 넣어둠
tuple<int,int,int> edge[100005];
// 최소 신장에 대한 정보 저장
vector<int> p(10005,-1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int U, int V){
    U = find(U); V = find(V);
    // 같다는 의미 자체가 둘 다 -1임을 의미하고
    // 결국 이미 노드 간의 연결이 이루어졌음을 의미해
    // 더 이상 계산은 의미가 없다.
    if(U == V) return false;

    // 각 노드들의 부모가 같은 경우는 오직 -1인 경우이다.
    // Find 과정에서 최 상단 Root를 가져오기 때문
    // 이 말은 즉, 찾은 값 둘의 부모는 다 Root node임을 의미하기에
    // 해당 함수 사용 시 u < v 기에, 노드 숫자가 더 작은 U의 값을 줄여둔다.
    if(p[U] == p[V]) p[U]--;

    // u의 부모가 v보다 작은 경우는 2개 중 하나다.
    // 위에 == 함수에서 U와 V 중 더 작은 수를 기반으로 Index를 더 줄이기에, 우선순위가 더 높은 U쪽으로 닿았거나,
    // 둘다 Root 부모가 존재하지만, 두 부모 Root Node 값이 다르지만, V가 U보다 우선순위가 낮아 V를 U로 편입시키는 과정이다.
    if(p[U] < p[V]) p[V] = U;

    // 둘다 속하지 않은 경우는 U가 더 큰 케이스기에 그냥 V를 p[U]로 상속 시킨다.
    else p[U] = V;

    // 편입은 시켰지만, 우선은 다른 그룹이였었기에 true를 반환한다.
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }

    // Sort 기준이 길이가 짧고, 시작 점이 가장 적은 것을 기준으로 값을 넣는다.
    // 뭐든 길이가 짧은 것을 기준으로 먼저 간선과 그룹을 지어두는 것으로
    // 최소 신장트리를 위한 조건이 우선 충족된다.
    sort(edge, edge + e);

    int cnt = 0;
    int ans = 0;

    // 소팅한 간선들 기준으로 필터링과 union 과정으로
    // 값들을 넣어둔다.
    for(int i = 0; i < e; i++) {
        int a, b, cost;
        // tuple에서 각각 값 하나씩 꺼내오기.
        tie(cost, a, b) = edge[i];

        // 같은 그룹인 경우는 굳이 계산할 필요가 없다.
        // 같은 그룹인 경우는 이미 신장 트리에 들어가 있기에
        // 굳이 또 계산할 필요가 없는 경우를 의미한다.
        // 즉 실제 필터링은 이 과정에서 걸러진다고 할 수 있다.
        if (!is_diff_group(a, b)) {
            continue;
        }

        // 그리디 개념이기에 이미 연결된 정보들은 전부 최소 신장 트리로, 굳이 어디서 필터링 걸기 이전에
        // 데이터가 들어가는 시점에서 필터링이 걸려버렸기에, 단순히 연산하면 해결된다.
        ans += cost;
        cnt += 1;
        // 노드 갯수가 이미 모든 노드를 순회한 경우이기에, 굳이 더 이동하지 말고
        // 바로 탈출시켜 시간 복잡도를 줄인다.
        if (cnt == v - 1) break;
    }

    printf("%d", ans);
}