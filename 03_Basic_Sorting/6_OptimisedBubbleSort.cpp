#include<bits/stdc++.h>
using namespace std;

vector<int> optimizedBubbleSort(vector<int> arr){
    // your code  goes here
    int i, j, n=arr.size();

    
    // �� ���̶� swap �� �Ͼ�� �� �ƴ� �� üũ�ϴ� �Լ�
    bool swapped{ false };

    // ó�� ~ �� �ȴ� ȸ�� => �� n-1 �� ���� ����
    for (i = 0; i < n-1; i++)
    {

        // ù ���� �� �̹� ������ �� �������� �ƴ����� Ȯ���� �� �ִ�
        // swapped = false;

        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);

                // swap �߻�
                swapped = true;
            }
        }
 
        // IF no two elements were swapped by inner loop, then break
        // ù ��° �������� Ȯ���ϸ� �ȴ�
        if (i == 0 && swapped == false) break;
    }
   
   return arr;
}