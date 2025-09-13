#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int Temp = name.length() - 1;

    for (int i = 0; i < name.length(); i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        int nextIndex = i + 1;
        while (nextIndex < name.length() && name[nextIndex] == 'A') {
            nextIndex++;
        }

        int moveBack = i * 2 + (name.length() - nextIndex);
        int moveForward = (name.length() - nextIndex) * 2 + i;

        Temp = min(min(moveForward, moveBack), Temp);
    }

    return answer + Temp;
}