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


/*
    Tiling ���� => 1*M Ÿ���� N �� ����, ���� M, ���� N ���簢���� ����� �ʹ�. �̶� ���� �� �ִ� �� ����� ����?

    ���δ� M ���� ����, ���� �ʺ� ��� �޶����� �� �κ��� ä��� ����� ���� �� ���İ� ����
    1*M Ÿ�� => M*M ������ ä�� �� �����ؾ� �Ѵ� => �������� Ÿ���� �������� ä���� �ϴ� 1 ���� ���ۿ� ���µ�,
    M*M ������ ���, ���η� ������ ä�� �� �����Ƿ� ����� ���� 2���� �����Ѵ�

    ���� ~ �׳� �ƿ� M*M ������ ��Ȳ�� Base Case �� ���Ĺ��� => �̶��� ä�� �� �ִ� ����� ���� 1 ���� �ΰ� ��Ȯ�ϴϱ�
    Base Case �� �� ���Խ�Ű��
    M*M �̻���ʹ� => sub problem ���� ����� ����
    => ���� �� Ÿ���� ������ ��,
    => ���� �� Ÿ�ϵ��� ������ ��,

    Expected Time Complexity: O(2^n)
*/
int tiles(int witdh, int m) {
    if (witdh < m) return 1;       // Base Case

    int op1 = tiles(witdh - 1, m); // ���� �� Ÿ���� �������� ��
    int op2 = tiles(witdh - m, m); // ���� �� M ���� Ÿ�ϵ��� ������ ��

    return (op1 + op2); // Sub Problem �� �ذ��ϰ�, �� ����� ���Ѵ� => �̹� �ܰ� �۾�
}


/*
������ �Լ� ǥ�ø� �̿� => ��ȭ��, main problem �� sub problem ���� ���踦 ǥ���ϸ� �� ����ϰ� ������ �� �ִ�
*/