
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, s[15151], cnt;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n);
    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] + s[r] == m) {
            l++;
            r--;
            cnt++;
        }
        else if (m < s[l] + s[r]) {
            r--;
        }
        else {
            l++;
        }
    }
    cout << cnt;
    return 0;
}