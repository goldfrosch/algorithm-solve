#include <iostream>
#include <vector>

#define MAX 1000001

using namespace std;

int subwayCount, constCount;

struct node {
	int past = 0;
	int next = 0;
};

node subway[MAX];

// 첫 정류장
vector<int> first;

void executeBN(int from, int to) {
	std::cout << subway[from].next << "\n";

	subway[to].next = subway[from].next;
	subway[to].past = from;

	subway[subway[from].next].past = to;
	subway[from].next = to;
}

void executeBP(int from, int to) {
	std::cout << subway[from].past << "\n";

	subway[to].past = subway[from].past;
	subway[to].next = from;

	subway[subway[from].past].next = to;
	subway[from].past = to;
}

void executeCN(int from) {
	int fromNextSubwayId = subway[from].next;
	std::cout << fromNextSubwayId << "\n";

	subway[subway[fromNextSubwayId].next].past = subway[fromNextSubwayId].past;
	subway[from].next = subway[fromNextSubwayId].next;

	subway[fromNextSubwayId] = {};
}

void executeCP(int from) {
	int fromPastSubwayId = subway[from].past;
	std::cout << fromPastSubwayId << "\n";

	subway[from].past = subway[fromPastSubwayId].past;
	subway[subway[fromPastSubwayId].past].next = subway[fromPastSubwayId].next;

	subway[fromPastSubwayId] = {};
}

int main()
{
	int n, count;

	int from, to, answer;
	string cmd;
	
	// cin, cout 최적화
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> subwayCount >> count;

	if (subwayCount == 1) {
		cin >> n;
		node t = {};
		// n 즉 정류장의 고유 번호를 배열 위치로 사용함
		subway[n] = t;
	}

	else {
		for (int i = 0; i < subwayCount; ++i) {
			cin >> n;
			node t = {};
			// 먼저 관련된 노드 정보 추가
			first.push_back(n);

			int current = i == 0 ? 0 : i - 1;

			// 이전 역의 ID 등록
			t.past = first[current];

			// 이전 스택의 다음 역 ID 정보 등록
			subway[first[current]].next = first[i];

			// 마지막 값에 대한 추가 설정
			if (i == subwayCount - 1) {
				// 마지막 노드로써 처음 정보를 같이 저장
				t.next = first[0];
				subway[first[0]].past = first[subwayCount - 1];
			}

			subway[first[i]] = t;
		}
	}

	
	for (int i = 0; i < count; i++) {
		std::cin >> cmd;
		std::cin >> from;

		if (cmd[0] == 'B') {
			std::cin >> to;
			if (cmd == "BN") {
				executeBN(from, to);
			}
			else if (cmd == "BP") {
				executeBP(from, to);
			}
		}
		else {
			if (cmd == "CN") {
				executeCN(from);
			}
			else if (cmd == "CP") {
				executeCP(from);
			}
		}
	}
	
	return 0;
}