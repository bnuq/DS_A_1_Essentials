#include <vector>
using namespace std;

/*
�־��� �迭���� ������ ���� k �� �����ϴ� ��� �ε����� �����ؼ� vector �� ��ƶ�
Recursion �̿�, �տ������� ������� index �� ��� �ͱ� ������,
�迭�� ��->�� ������ ����, ���� �ܰ� �۾� -> sub problem �ذ��ϴ� ������� ����
*/
// recursion �� ���� �ʿ��� helper function, ���ʿ��� ���縦 reference �� ���� ���Ҵ�
void findK(vector<int>& vec, int i, int k, const vector<int>& v) {
    if (i >= v.size()) return;       // Base Case = ������ ��Ұ� ���̻� ����

    if (v[i] == k) vec.push_back(i); // ���� �ܰ� �۾� => ���� ��� �ε����� ���ϴ� ���� ���� �� Ȯ��

    findK(vec, i + 1, k, v);         // ���� �޺κ� sub problem �� �ذ�
}
vector<int> findAllOccurences(int k, vector<int> v) {
    vector<int> kIndex{};
    findK(kIndex, 0, k, v);
    return kIndex;
}