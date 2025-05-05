#include <iostream>

int MonthToDay[13] = {0, 31,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1924
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Month, Day;
    std::cin >> Month >> Day;

    int Date = Day;

    for (int i = 0; i < Month; i++) {
        Date += MonthToDay[i];
    }

    switch (Date % 7) {
        case 0:
            printf("SUN");
            break;
        case 1:
            printf("MON");
            break;
        case 2:
            printf("TUE");
            break;
        case 3:
            printf("WED");
            break;
        case 4:
            printf("THU");
            break;
        case 5:
            printf("FRI");
            break;
        case 6:
            printf("SAT");
            break;
    };
    
    return 0;
}