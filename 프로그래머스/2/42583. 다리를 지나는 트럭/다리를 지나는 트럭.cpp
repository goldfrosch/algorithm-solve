#include <vector>
#include <queue>

using namespace std;

struct BridgeInfo {
    int weight = 0;
    int startTime = 0;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> start;
    queue<BridgeInfo> wait;
    int waitTempSum = 0;

    for (const auto &item: truck_weights) {
        start.push(item);
    }

    while(true) {
        answer += 1;

        // 트럭이 다리를 지나가는 과정
        if (!wait.empty()) {
            while (true) {
                if (wait.empty()) {
                    break;
                }

                auto [truckWeight, truckStartTime] = wait.front();
                if (bridge_length > answer - truckStartTime) {
                    break;
                }

                waitTempSum -= truckWeight;
                wait.pop();
            }
        }

        // 트럭이 다리에 오르는 과정
        if (!start.empty()) {
            if (waitTempSum + start.front() <= weight) {
                wait.push({start.front(), answer});
                waitTempSum += start.front();
                start.pop();
            }
        }
        
        if (start.empty() && wait.empty()) {
            break;
        }
    }

    return answer;
}