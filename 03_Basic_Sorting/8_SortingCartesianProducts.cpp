//Expected Time Complexity :O(N log N)


#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
{
    sort(v.begin(), v.end());
    /*
        pair 에 대한 비교가 이미 정해져 있다
        first 먼저 비교하고 같으면 second 비교하는 방식으로...
    */
    return v;
}


vector<pair<int, int>> my_sortCartesian(vector<pair<int, int>> v)
{
    int N = v.size();
    // your code goes here

    sort(v.begin(), v.end(), [](const auto& e1, const auto& e2)
        {
            if (e1.first != e2.first) return e1.first < e2.first;
            else return e1.second < e2.second;
        });

    return v;
}