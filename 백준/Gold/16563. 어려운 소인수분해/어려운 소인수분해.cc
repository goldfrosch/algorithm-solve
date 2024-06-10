#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

const int MAX = 5000000;

int N;
int Prime[MAX + 1];

void init(){
    for (int i = 2; i <= MAX; i++)
        Prime[i] = i;

    for (int i = 2; i <= sqrt(MAX); i++)
        if (Prime[i] == i)
            for (int j = i * i; j <= MAX; j += i)
                if (Prime[j] == j)
                    Prime[j] = i;
}

void calc(int num){
    while (num > 1){
        cout << Prime[num] << " ";
        num /= Prime[num];
    }
    cout << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    init();

    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        calc(num);
    }

    return 0;
}