#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> Uuid;

void SplitLog(const string& record, vector<string>& result) {
    string temp;

    for (const auto &item: record) {
        if (item == ' ') {
            result.push_back(temp);
            temp = "";
            continue;
        }
        temp += item;
    }

    result.push_back(temp);
}

void ChangeName(const string& uuid, const string& nickname) {
    Uuid[uuid] = nickname;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> LogList;

    for (const auto &item: record) {
        vector<string> Log;
        SplitLog(item, Log);

        // 일단 뭐든 상관 없이 모든 레코드는 집어넣기
        LogList.push_back({Log[0], Log[1]});

        if (Log[0] == "Enter") {
            ChangeName(Log[1], Log[2]);
            continue;
        }
        if (Log[0] == "Change") {
            ChangeName(Log[1], Log[2]);
            continue;
        }
    }

    for (const auto &item: LogList) {
        if (item.first == "Enter") {
            answer.push_back(Uuid[item.second] + "님이 들어왔습니다.");
        }
        if (item.first == "Leave") {
            answer.push_back(Uuid[item.second] + "님이 나갔습니다.");
        }
    }

    return answer;
}