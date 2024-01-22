#include <list>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

void coutString(list<char> charList) {
	for (char c : charList) {
		std::cout << c;
	}
	std::cout << "\n";
}

int main()
{
	int commandCount;

	string keyword;

	std::cin >> keyword;

	list<char> stringItem(keyword.begin(),keyword.end());
	auto cursor = stringItem.end();

	std::cin >> commandCount;

	for (int i = 0; i < commandCount; i++) {
		char command, key;
		std::cin >> command;

		if (command == 'L') {
			if (cursor != stringItem.begin()) {
				cursor--;
			}
		}
		else if (command == 'D') {
			if (cursor != stringItem.end()) {
				cursor++;
			}
		}
		else if (command == 'B') {
			if (cursor != stringItem.begin()) {
				cursor--;
				cursor = stringItem.erase(cursor);
			}
		}
		else if (command == 'P') {
			std::cin >> key;
			stringItem.insert(cursor, key);
		}
	}

	coutString(stringItem);

	return 0;
}