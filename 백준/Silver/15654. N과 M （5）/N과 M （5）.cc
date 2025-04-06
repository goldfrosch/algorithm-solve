#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int NumberArray[15];
int ValueArray[15];
bool IsVisited[15];

void BackTracking(int Count) {
    if (Count == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", ValueArray[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 0;i < N; i++){
        if(!IsVisited[i]){
            ValueArray[Count] = NumberArray[i];
            IsVisited[i] = true;
            BackTracking(Count + 1);
            IsVisited[i] = false;
        }
    }
}

int main() {
    // https://www.acmicpc.net/problem/15652
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> NumberArray[i];
        IsVisited[NumberArray[i]] = false;
    }

    sort(NumberArray, NumberArray + N);

    BackTracking(0);
}