#include <vector>

using namespace std;

int EmoticonLen;
const int SalePercents[4] = {40,30,20,10};
vector<vector<int>> AllSalePercents;

void Dfs(vector<int> p) {
    if (p.size() == EmoticonLen) {
        AllSalePercents.push_back(p);
        return;
    }

    for (const auto &item: SalePercents) {
        p.push_back(item);
        Dfs(p);
        p.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    answer.resize(2, 0);

    EmoticonLen = emoticons.size();

    Dfs({});

    for (const auto &SalePercentList: AllSalePercents) {
        auto ListSize = SalePercentList.size();
        int TempEmoticons[ListSize];

        for (int i = 0; i < ListSize; i++) {
            TempEmoticons[i] = ((100 - SalePercentList[i]) * emoticons[i]) / 100;
        }

        int EmoticonPlusCount = 0;
        int Money = 0;

        for (const auto &user: users) {
            int Temp = 0;

            for (int i = 0; i < ListSize; i++) {
                if (SalePercentList[i] >= user[0]) {
                    Temp += TempEmoticons[i];
                }
            }

            if (Temp >= user[1]) {
                EmoticonPlusCount += 1;
            } else {
                Money += Temp;
            }
        }

        if (answer[0] < EmoticonPlusCount) {
            answer[0] = EmoticonPlusCount;
            answer[1] = Money;
        } else if (answer[0] == EmoticonPlusCount) {
            if (answer[1] < Money) {
                answer[1] = Money;
            }
        }
    }

    return answer;
}