#include <vector>
using namespace std;


/*
    주어진 배열에서 임의의 숫자 k 가 등장하는 모든 인덱스를 조사해서 vector 에 담아라
    Recursion 이용, 앞에서부터 순서대로 index 를 담고 싶기 때문에,
    배열의 앞->뒤 순서로 진행, 현재 단계 작업 -> sub problem 해결하는 방식으로 진행
*/
// recursion 을 위해 필요한 helper function, 불필요한 복사를 reference 를 통해 막았다
void findK(vector<int>& vec, int i, int k, const vector<int>& v) {
    if (i >= v.size()) return;       // Base Case = 조사할 요소가 더이상 없다

    if (v[i] == k) vec.push_back(i); // 현재 단계 작업 => 현재 대상 인덱스가 원하는 값과 같은 지 확인

    findK(vec, i + 1, k, v);         // 이후 뒷부분 sub problem 을 해결
}
vector<int> findAllOccurences(int k, vector<int> v) {
    vector<int> kIndex{};
    findK(kIndex, 0, k, v);
    return kIndex;
}


/*
    Tiling 문제 => 1*M 타일이 N 개 존재, 세로 M, 가로 N 직사각형을 만들고 싶다. 이때 만들 수 있는 총 경우의 수는?

    세로는 M 으로 고정, 가로 너비가 계속 달라지고 이 부분을 채우는 경우의 수가 몇 개냐가 관건
    1*M 타일 => M*M 영역을 채울 때 주의해야 한다 => 그전에는 타일을 세워서만 채워야 하니 1 가지 경우밖에 없는데,
    M*M 영역의 경우, 가로로 뉘여서 채울 수 있으므로 경우의 수가 2가지 존재한다

    따라서 ~ 그냥 아예 M*M 이전의 상황을 Base Case 로 퉁쳐버려 => 이때는 채울 수 있는 경우의 수가 1 가지 인게 명확하니까
    Base Case 로 다 포함시키자
    M*M 이상부터는 => sub problem 으로 나누어서 생각
    => 가장 앞 타일을 세웠을 때,
    => 가장 앞 타일들을 뉘였을 때,

    Expected Time Complexity: O(2^n)
*/
int tiles(int witdh, int m) {
    if (witdh < m) return 1;       // Base Case

    int op1 = tiles(witdh - 1, m); // 가장 앞 타일이 세워졌을 때
    int op2 = tiles(witdh - m, m); // 가장 앞 M 개의 타일들이 누웠을 때

    return (op1 + op2); // Sub Problem 을 해결하고, 그 결과를 더한다 => 이번 단계 작업
}


/*
수학의 함수 표시를 이용 => 점화식, main problem 과 sub problem 간의 관계를 표현하면 더 명백하게 이해할 수 있다
*/