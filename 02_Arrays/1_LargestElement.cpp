//Expected Time Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

int my_largestElement(vector<int> arr) {
    int largest{ arr[0] }; // �迭 ù ��° ���� �ּ� ������ ���� ����

    for (size_t i = 1; i < arr.size(); i++)
        // ���鼭 Ȯ��
        largest = (arr[i] > largest) ? arr[i] : largest;

    return largest;

}

int largestElement(vector<int> A) {
    
     // ���� �ּҰ����� �ʱ�ȭ
     int largestEle = INT_MIN;
     
     // �����ϰ� max �Լ� ���
     for (auto element : A ) {
         largestEle = max(largestEle, element);
     }
     
     return largestEle;
}