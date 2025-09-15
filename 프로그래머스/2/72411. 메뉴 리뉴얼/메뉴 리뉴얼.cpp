#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<bool> IsVisited;
map<string, int> MenuList;

void GetCourse(vector<string>& Result, string Menu, const string& Order, const int RemainCount, const int StartIdx) {
    if (RemainCount == 0) {
        sort(Menu.begin(), Menu.end());
        Result.push_back(Menu);
        return;
    }

    for (int i = (StartIdx == -1 ? 0 : StartIdx); i < Order.length(); i++) {
        if (IsVisited[i]) {
            continue;
        }

        Menu.push_back(Order[i]);
        IsVisited[i] = true;
        GetCourse(Result, Menu, Order, RemainCount - 1, i);
        IsVisited[i] = false;
        Menu.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<string> Menus;

    IsVisited.resize(12, false);
    for (const auto &CourseCount: course) {
        for (const auto &Order: orders) {
            IsVisited.assign(12, false);
            GetCourse(Menus, "", Order, CourseCount, -1);
        }

        int Max = 0;
        for (const auto &item: Menus) {
            MenuList[item] += 1;
            if (Max < MenuList[item]) {
                Max = MenuList[item];
            }
        }

        for (const auto &[MenuName, Count]: MenuList) {
            if (Count == Max && Count > 1) {
                answer.push_back(MenuName);
            }
        }

        Menus.clear();
        MenuList.clear();
    }

    sort(answer.begin(), answer.end());
    return answer;
}