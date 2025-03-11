#include <iostream>
#include <string>
#include <set>
using namespace std;

int N, M;
string shiritori[100];
set<string> st;
int idx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string& s = shiritori[i];
		cin >> s;
		
		if (s == "?") idx = i;
		else st.insert(s);
	}

	cin >> M;

	while (M--) {
		string s; cin >> s;
		if (idx > 0) {
			if (s.front() != shiritori[idx - 1].back()) continue;
		}
		if (idx + 1 < N) {
			if (s.back() != shiritori[idx + 1].front()) continue;
		}
		if (st.count(s)) continue;

		cout << s;
	}
}