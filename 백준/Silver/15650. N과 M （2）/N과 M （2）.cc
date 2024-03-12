#include <iostream>

using namespace std;

int N, M;

int arr[10];
bool isUsed[10];

void backTrack(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!isUsed[i]) {
            if ((k - 1 >= 0 && arr[k - 1] < i) || k == 0) {
                isUsed[i] = true;
                arr[k] = i;
                backTrack(k + 1);
                isUsed[i] = false;
            }
        }
    }
}

int main() {
    std::cin >> N >> M;

    backTrack(0);

    return 0;
}
