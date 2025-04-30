#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/2941
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    std::cin >> N;

    int ans = 0, i = 0;

    while (i < N.length()) {
        if (N[i] == 'c') {
            if (N[i + 1] == '=')
                i++;
            else if (N[i + 1] == '-')
                i++;
        }
        else if (N[i] == 'd') {
            if (N[i + 1] == '-')
                i++;
            else if (N[i + 1] == 'z' && N[i + 2] == '=')
                i += 2;
        }
        else if (N[i] == 'l') {
            if (N[i + 1] == 'j')
                i++;
        }
        else if (N[i] == 'n') {
            if (N[i + 1] == 'j')
                i++;
        }
        else if (N[i] == 's') {
            if (N[i + 1] == '=')
                i++;
        }
        else if (N[i] == 'z') {
            if (N[i + 1] == '=')
                i++;
        }

        ans++;
        i++;
    }

    printf("%d", ans);
    
    return 0;
}