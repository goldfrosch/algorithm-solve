#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer;

    string temp;
    vector<int> List;

    for (const auto &item: s) {
        if (item == ' ') {
            List.push_back(stoi(temp));
            temp = "";
            continue;
        }

        temp += item;
    }

    List.push_back(stoi(temp));

    sort(List.begin(), List.end());

    answer += to_string(List[0]);
    answer += " ";
    answer += to_string(List[List.size() - 1]);

    return answer;
}