#include <iostream>
#include <map>

using namespace std;

map<char, int> roms = {
	{'I', 1},
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100},
	{'D', 500},
	{'M', 1000}
};


string returnNumberToRomanText(int number) {
	int record = number;
	string result = "";


	while (record != 0) {
		if (record >= 1000) {
			for (int i = 0; i < record / 1000; i++) {
				result += "M";
			}
			record %= 1000;
		} else if (record >= 100) {
			if (record / 100 == 9) {
				result += "CM";
				record -= 900;
			}
			else if (record / 100 == 4) {
				result += "CD";
				record -= 400;
			}
			else if (record >= 500) {
				result += "D";
				record -= 500;
			}
			else {
				for (int i = 0; i < record / 100; i++) {
					result += "C";
				}

				record %= 100;
			}
		}
		else if (record >= 10) {
			if (record / 10 == 9) {
				result += "XC";
				record -= 90;
			}
			else if (record / 10 == 4) {
				result += "XL";
				record -= 40;
			}
			else if (record >= 50) {
				result += "L";
				record -= 50;
			}
			else {
				for (int i = 0; i < record / 10; i++) {
					result += "X";
				}
				record %= 10;
			}
		}
		else {
			if (record == 9) {
				result += "IX";
				record = 0;
			}
			else if (record == 4) {
				result += "IV";
				record = 0;
			}
			else if (record >= 5) {
				result += "V";
				record -= 5;
			}
			else {
				for (int i = 0; i < record; i++) {
					result += "I";
				}
				record = 0;
			}
		}
	}
	return result;
}



int parsingRomanToNumber(string rom) {
	int len = rom.length();
	int ans = 0;
	string temp;
	for (int i = 0; i < len; i++) {
		if (i + 1 != len && roms[rom[i]] < roms[rom[i + 1]]) {
			ans -= roms[rom[i]];
		}
		else {
			ans += roms[rom[i]];
		}
	}

	return ans;
}

int main()
{
	int number;
	string s1, s2;

	std::cin >> s1 >> s2;

	number = parsingRomanToNumber(s1) + parsingRomanToNumber(s2);

	std::cout << number << "\n";

	std::cout << returnNumberToRomanText(number);

	return 0;
}