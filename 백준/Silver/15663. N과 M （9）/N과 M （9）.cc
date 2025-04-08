#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[9] = {0,};
int Value[9] = {0, };
bool visited[9] = {0,};

void backtrack(int cnt)
{
    if(cnt == M)
    {
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int Temp = 0;
    for(int i = 0; i < N; i++)
    {
        if (!visited[i] && Temp != Value[i]) {
            // 매 재귀함수마다 방문한 곳이 아닌 다른 곳을 true로 처리해 중첩되는 문제를 없앤다.
            visited[i] = true;
            // 실행할 스택 값에 i값을 넣어둬 이후 갯수가 다 찰 때 일렬로 출력하게
            Temp = Value[i];
            arr[cnt] = Value[i];
            backtrack(cnt + 1);
            // 재귀함수 실행 이후 다시 false로 변경해 다시 접근 가능하게 설정
            visited[i] = false;
        }
    }
}


int main() {
    // https://www.acmicpc.net/problem/15663
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> Value[i];
    }

    sort(Value, Value + N);
    backtrack(0);

    return 0;
}