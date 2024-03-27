#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int count;
	std::cin >> count;
	int number;
	vector<int> num;
	for (int i = 0; i < count; i++) {
		std::cin >> number;
		num.push_back(number);
	}
	sort(num.begin(), num.end());

	for (int i = 0;i < count; i++) {
		std::cout << num[i] << "\n";
	}
}