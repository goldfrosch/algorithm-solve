#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> LZW;

vector<int> solution(string msg) {
    vector<int> answer;

    int index = 1;
    for (int i = 'A'; i <= 'Z'; i++) {
        string Key;
        Key += static_cast<char>(i);
        LZW[Key] = index;
        index += 1;
    }

    string Temp;
    for (int i = 0; i < msg.length(); i++) {
        // 한글자는 있을 수 밖에 없다. 대문자만 들어가기 때문에
        Temp += msg[i];

        for (int j = i + 1; j <= msg.length(); j++) {
            int PrevKey = LZW[Temp];

            if (LZW[Temp + msg[j]] == 0) {
                answer.push_back(PrevKey);
                LZW[Temp + msg[j]] = index;
                Temp = "";
                index += 1;
                i = j - 1;
                break;
            }

            Temp += msg[j];
        }
    }

    return answer;
}