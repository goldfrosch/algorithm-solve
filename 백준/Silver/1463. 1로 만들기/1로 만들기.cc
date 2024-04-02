#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//문제 https://www.acmicpc.net/problem/1463
int main() {
	int num;
	std::cin >> num;
	vector<int> test(num + 1);

	//bottom-up
	//처음에 2부터 각각 나눠지는 횟수를 구하면서 최소한의 값을 계속
	//구하는 상태에서 1을 더하고 그 값과 비교해 계속 +하는 방식
	test[1] = 0;
	for (int i = 2; i <= num; i++) {
		test[i] = test[i - 1] + 1;
		if (!(i % 3)) {
			/* cout << i << "," << min(test[i], test[i / 3] + 1);
			printf("\n"); */
			test[i] = min(test[i], test[i / 3] + 1);
		}
		if (!(i % 2)) {
			/* cout << i << "," << min(test[i], test[i / 2] + 1);
			printf("\n"); */
			test[i] = min(test[i], test[i / 2] + 1);
		}
	}

	cout << test[num] << endl;
	return 0;
}