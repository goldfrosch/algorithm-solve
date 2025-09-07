#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    std::cin >> N >> K;

    priority_queue<int> Queue;

    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;

        Queue.push(temp);
    }

    for (int i = 0; i < N - K; i++) {
        Queue.pop();
    }

    printf("%d", Queue.top());

    return 0;
}