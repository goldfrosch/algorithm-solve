#include <iostream>

using namespace std;

int N;
int result = 0;

bool isPrime(int number) {
    if (number == 1) return false;

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }

    return true;
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int k;
        std::cin >> k;

        if (isPrime(k)) result++;
    }

    std::cout << result;
    return 0;
}