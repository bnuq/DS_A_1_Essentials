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
    
    // ó�� ���� ���� 0�� �̸� �־�ΰ�
    x.push_back(0); y.push_back(0);
    
    ll maxx = INT_MIN, maxy = INT_MIN;

    // x ����, y ���и� �̸� �� ���� ������
    for(int i=0; i<v.size(); i++)
    {
        x.push_back(v[i].first), y.push_back(v[i].second);
    }
    

    // x.push_back(W); y.push_back(H);
    // ���и� ��Ƴ��� ������ ����
    sort(all(x));
    sort(all(y));

    
    // ���� ���� �� �� �ִ밪�� ã�´� => ��� �ִ� ���� �߿����� �ʰ�, �׳� �ִ밪�� �󸶳ĸ� �˸� �Ǵ� �ſ���
    for (ll i = 1; i < x.size(); i++) maxx = max(maxx, x[i] - x[i - 1] - 1);
    for (ll i = 1; i < y.size(); i++) maxy = max(maxy, y[i] - y[i - 1] - 1);
    
    
    // ���� ���� ���ϰ�, ������ �� �κ� ���� ��
    maxx = max(maxx, W - x[x.size() - 1] );
    maxy = max(maxy, H- y[y.size() - 1]);

    return (maxx * maxy);
    
}



// ���� �� ����, ��·�� �������� ���̸� �� Ȯ���ϴϱ�, O(n^2) �ΰ�?
int my_defkin(int W, int H, vector<pair<int, int>> position)
{
    // your code goes here

    // ������ ���� ����
    vector<int> xRange;
    vector<int> yRange;

    // �׳� ������ ���� �̾Ƴ���
    for (const auto& e : position) {
        xRange.emplace_back(e.first);
        yRange.emplace_back(e.second);
    }

    // ��Ƴ��� ���е��� ����
    sort(xRange.begin(), xRange.end());
    sort(yRange.begin(), yRange.end());
    

    // ���е� ���� �� ��, �ִ밪�� ã�´�
    int maxX{ 0 }, maxY{ 0 };
    int prevX{ 0 }, prevY{ 0 };

    // x ���п� ���ؼ�
    for (auto x : xRange) {
        int temp = (x - 1) - prevX;
        maxX = max(maxX, temp);
        prevX = x;
    }
    // ������ ������ ���
    maxX = max(maxX, W - prevX);



    // y ���п� ���ؼ�
    for (auto y : yRange) {
        int temp = (y - 1) - prevY;
        maxY = max(maxY, temp);
        prevY = y;
    }
    // ������ ������ ���
    maxY = max(maxY, H - prevY);


    // ���� �� ���� �� �ִ밪�� �� => �ִ� ����
    return maxX * maxY;
}