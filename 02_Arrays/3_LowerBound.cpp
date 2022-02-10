//Expected Time Complexity: O(logN)
//Hint: Binary Search


#include<bits/stdc++.h>
using namespace std;


int my_lowerBound(vector<int> A, int Val) {
    // your code goes here

    int lowerbound{ -1 };

    // �׳� �迭 ��ü�� �ѹ� �ȱ�
    for (auto x : A)
    {
        if (x <= Val) lowerbound = x;
        else break;
    }

    return lowerbound;
}


// sorted array => binary search ���
int lowerBound(vector<int> A, int Val) {
    
    int sz = A.size();
    
    // Ž���ϴ� �ε��� => �� ������ ����
    int l = 0, r = (sz-1);
    
    int answer = -1;
    

    // ������ ���� ��ġ�� ��߳��� �ȴ�
    while (l <= r) {
        // �߰� ��ġ ���ϰ�
        int mid = (l + r) / 2;

        // l ~ mid ���̿� �ִ��� Ȯ��
        if (A[mid] > Val) {
            // r ��ġ ����
            r = mid-1;
        }
        // mid <= < r ���̿� ���� ��
        else {
            // �ϴ� mid ��ġ = answer
            answer = A[mid];

            // l ��ġ ����
            l = mid+1;
        }
    }
    
    return answer;
    
}