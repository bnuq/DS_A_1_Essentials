#include <vector>
#include <algorithm>
using namespace std;

/*
* std::pair �� ���� default ����
* first �� non-decreasing order �� ����
* first �� ���ٸ�, second �� non-decreasing order �� ����
*/

/* 9.
* Ư�� ���� ������ ���� �迭�� �־��� ��, �迭�� �� ���� ���̷� Ư�� �� ���ϸ�
* ����� �ִ� ����� ���� ���϶�
*/
int pairSticks(vector<int> length, int D)
{
    // �ϴ� �迭 ������ ���� �Ѵ� => �ϴ� ������ ���ĵǾ� ������, �迭�� �ٷ�� ����
    sort(length.begin(), length.end());
    int res = 0;
    for (int i = 0; i < length.size() - 1; i++)
    {
        // �ִ��� ���� ����� �͵� ���� ��� ���� ���ؾ�, �ִ��� ���� ����� ���� ���� �� �ִ�
        if (length[i + 1] - length[i] <= D) { res++; i++; } // i ����, 2ĭ ���� ȿ���� �����
    }

    return res;
}

