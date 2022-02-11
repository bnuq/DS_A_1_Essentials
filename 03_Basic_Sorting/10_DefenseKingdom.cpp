//Expected Time Complexity= O(N log N)
//Find the largest distance from both W and H axis and take their product.



#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
#define all(v) v.begin(), v.end()

int defkin(int W, int H, vector<pair<int, int>> position)
{
    // your code goes here
    vector<pair<int, int>> v = position;
    int w = W, h = H;
    vector<ll> x, y;
    
    // 처음 시작 값인 0을 미리 넣어두고
    x.push_back(0); y.push_back(0);
    
    ll maxx = INT_MIN, maxy = INT_MIN;

    // x 성분, y 성분만 미리 빼 놓은 다음에
    for(int i=0; i<v.size(); i++)
    {
        x.push_back(v[i].first), y.push_back(v[i].second);
    }
    

    // x.push_back(W); y.push_back(H);
    // 성분만 모아놓은 다음에 정렬
    sort(all(x));
    sort(all(y));

    
    // 성분 사이 값 중 최대값을 찾는다 => 어디 있는 지는 중요하지 않고, 그냥 최대값이 얼마냐만 알면 되는 거였네
    for (ll i = 1; i < x.size(); i++) maxx = max(maxx, x[i] - x[i - 1] - 1);
    for (ll i = 1; i < y.size(); i++) maxy = max(maxy, y[i] - y[i - 1] - 1);
    
    
    // 구간 사이 값하고, 마지막 끝 부분 길이 비교
    maxx = max(maxx, W - x[x.size() - 1] );
    maxy = max(maxy, H- y[y.size() - 1]);

    return (maxx * maxy);
    
}



// 내가 한 경우는, 어쨌든 마지막에 넓이를 다 확인하니까, O(n^2) 인가?
int my_defkin(int W, int H, vector<pair<int, int>> position)
{
    // your code goes here

    // 성분을 담을 벡터
    vector<int> xRange;
    vector<int> yRange;

    // 그냥 성분을 먼저 뽑아낸다
    for (const auto& e : position) {
        xRange.emplace_back(e.first);
        yRange.emplace_back(e.second);
    }

    // 모아놓은 성분들을 정렬
    sort(xRange.begin(), xRange.end());
    sort(yRange.begin(), yRange.end());
    

    // 성분들 사이 값 중, 최대값을 찾는다
    int maxX{ 0 }, maxY{ 0 };
    int prevX{ 0 }, prevY{ 0 };

    // x 성분에 대해서
    for (auto x : xRange) {
        int temp = (x - 1) - prevX;
        maxX = max(maxX, temp);
        prevX = x;
    }
    // 마지막 구간도 계산
    maxX = max(maxX, W - prevX);



    // y 성분에 대해서
    for (auto y : yRange) {
        int temp = (y - 1) - prevY;
        maxY = max(maxY, temp);
        prevY = y;
    }
    // 마지막 구간도 계산
    maxY = max(maxY, H - prevY);


    // 구한 각 성분 별 최대값의 곱 => 최대 넓이
    return maxX * maxY;
}