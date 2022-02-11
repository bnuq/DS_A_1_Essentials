//Expected Complexity: O(N logN)


#include <vector>
#include <algorithm>
using namespace std;


int pairSticks(vector<int> length, int D)
{
    // your code goes here
    // �ϴ� ������ �� => ������ �ϸ�, ���� ó���� �ξ� ���ϴ�
    // ��ġ�� ������� Ȯ���Ǵϱ�
    sort(length.begin(), length.end());
    int res = 0;

    for(int i=0; i<length.size()-1; i++)
    {
        // �� �Ȱ��� ���⼭�� 2���� ���ϳ�
        // �ִ��� ������ �͵鳢�� ¦�� ���� ��, ���� ���ϱ� ���� ��� �ΰ���
        if (length[i + 1] - length[i] <= D) { res++; i++;}
    }

    return res;
}


int my_pairSticks(vector<int> length, int D)
{
    // your code goes here
    // �ϴ� ���� ���� �Ѵ�
    sort(length.begin(), length.end());

    // �׻� ���ϴ� �ε����� 1 ���̸� ���ڱ���
    int i1{ 0 }, i2{ 1 }, count{ 0 };


    while (i1 < length.size() and i2 < length.size()) {
        if (length[i2] - length[i1] <= D) {
            count++;

            // ���� ���� �Ѿ��
            i1 += 2;
            i2 += 2;
        }
        // �̹��� ���̰� ���̳� ���, i2 �� �����ϰ� �ϳ��� �� �˻��Ѵ�
        else {
            i1 = i2;
            i2 += 1;
        }

        
    }

    return count;

}