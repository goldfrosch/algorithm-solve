#include <iostream>
#include <set>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/15652
   set<string> List;
   for (int i = 0; i < 4; i++) {
       string Temp;
       std::cin >> Temp;

       List.insert(Temp);
   }

    for (auto i = List.begin(); i != List.end(); i++)
        for (auto j = List.begin(); j != List.end(); j++) {
            cout << *i << ' ' << *j << '\n';
        }

    return 0;
}