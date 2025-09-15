#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

map<string, string> History;
map<string, int> TimeHistory;
map<string, int> PayResult;

void GetRecord(const string& Log, vector<string>& Record) {
    string temp;
    for (const auto &item: Log) {
        if (item == ' ') {
            Record.push_back(temp);
            temp = "";
            continue;
        }

        temp += item;
    }
    Record.push_back(temp);
}

int GetMinutes(const string& Time) {
    string hour, minute;
    hour += Time[0];
    hour += Time[1];

    minute += Time[3];
    minute += Time[4];

    return stoi(hour) * 60 + stoi(minute);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int DefaultTime = fees[0];
    int DefaultPay = fees[1];
    int OverPerTime = fees[2];
    int OverPerPay = fees[3];

    for (const auto &record: records) {
        vector<string> NewRecord;
        GetRecord(record, NewRecord);

        string Time = NewRecord[0];
        string CarNum = NewRecord[1];
        string InOut = NewRecord[2];

        if (InOut == "IN") {
            History[CarNum] = Time;
        } else {
            TimeHistory[CarNum] += (GetMinutes(Time) - GetMinutes(History[CarNum]));
            History.erase(CarNum);
        }
    }

    // 23:59분 임에도 아직도 안나간 사람에 대한 처리
    for (const auto &item: History) {
        if (TimeHistory[item.first] == 0) {
            TimeHistory[item.first] = GetMinutes("23:59") - GetMinutes(item.second);
            continue;
        }

        TimeHistory[item.first] += GetMinutes("23:59") - GetMinutes(item.second);
    }

    // 가격에 대한 최종 처리
    for (const auto &[CarNum, Time]: TimeHistory) {
        // 차량에 있는 사람은 일단 기본적으로 자기 요금은 넣고 생각함
        PayResult[CarNum] = DefaultPay;

        if (Time <= DefaultTime) {
            continue;
        }

        PayResult[CarNum] +=
                static_cast<int>(ceil(static_cast<float>((Time - DefaultTime)) / static_cast<float>(OverPerTime))) * OverPerPay;
    }

    answer.reserve(PayResult.size());

    for (const auto &item: PayResult) {
        answer.push_back(item.second);
    }

    return answer;
}