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