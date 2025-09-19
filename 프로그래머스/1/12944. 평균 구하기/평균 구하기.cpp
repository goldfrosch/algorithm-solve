#include <string>
#include <numeric>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    double sum = std::accumulate(arr.begin(), arr.end(), 0);
    
    return sum / arr.size();
}