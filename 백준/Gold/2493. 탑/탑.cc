#include <iostream>
#include <vector>

using namespace std;

struct node {
	int id = 0;
	int value = 0;
};

int main() {
	
	// cin, cout 최적화
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int count = 0;
	vector<node> tower;
	std::cin >> count;

	for (int i = 0; i < count; i++) {
		int num;

		std::cin >> num;

		node temp;
		temp.id = i + 1;
		temp.value = num;

		while (true) {
			if (tower.size() == 0) {
				tower.push_back(temp);
				std::cout << 0 << " ";
				break;
			}

			if (tower.back().value < num) {
				tower.pop_back();
			}
			else {
				std::cout << tower.back().id << " ";
				tower.push_back(temp);
				break;
			}
		}
	}

	return 0;
}