#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size(), 0);

    for (int i = 0; i < prices.size(); i++) {
        const int price = prices[i];

        for (int j = i + 1; j < prices.size(); j++) {
            answer[i] += 1;
            if (price > prices[j]) {
                break;
            }
        }
    }

    return answer;
}