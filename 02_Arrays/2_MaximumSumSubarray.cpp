//Expected Time Complexity: O(N)
//Hint: Kadane's Algorithm


#include<bits/stdc++.h>
using namespace std;


int my_maxSumSubarray(vector<int> A) {
    // sum �� ������ �� �� �ֱ� ������, �ּҰ����� �ʱ�ȭ �Ѵ�
    int curSum{ 0 }, maxSum{ INT_MIN };

    for (int i = 0; i < A.size(); i++)
    {
        // i �������� ���� ���� ���ϰ�
        curSum += A[i];

        // ���� ����� ���� Ȯ���Ѵ� => �ִ밪�� �Ǵ� ��?
        if (curSum > maxSum) maxSum = curSum;

        // ���� ���� ������ ���, �� ���� �ִ� ���̿��� ������ ���� ���ϴ� ���� ������ �ȵȴ�
        // �׷��ϱ� �������, ������ �ڸ��� �ٽ� �����ϵ��� �Ѵ�
        if (curSum < 0) curSum = 0;
    }

    return maxSum;
}


int maxSumSubarray(vector<int> A) {
    

    bool f =true;
    int rr=INT_MIN;


    // ��ü ���� Ȯ��
    for(auto x : A){
        if(x >0 ) f = false; // ����� �ϳ��� �ִ� �� Ȯ��
        if(x > rr) rr = x;   // �ִ밪
    }
    // ��� �������, �ִ밪�� ���� => �װ� max sum
    if(f) return rr;
    

    // �迭�� ��� ��Ұ� ������ �ƴ϶�� �� Ȯ���� ��,

    int maxSumFromPrevIndexToLeft = 0;
    
    int finalAnswer = 0;
    
    int temporary  = 0;
    
    int arraySize = A.size();
    for (int i = 0; i < arraySize; i++) {

        // ���� �� = ���� �� + ���� ��
        temporary = maxSumFromPrevIndexToLeft + A[i];

        // ���� ����, ���� ������ �� �۴� => ���� ���� ���̳ʽ���? �װ� ���̵�? => ���� ���� ������ �ȵȴ�
        // ��·�� ���� �ϳ��� ������ ���� ���� �� �۴ٸ�, ��� ���� �ʿ䰡 ����
        if (temporary < A[i]) {
            // ���� ���� ����Ѵ�, ���� ��ġ�� ���� �������� �缳��
            maxSumFromPrevIndexToLeft = A[i];
        }
        else {
            // ���� �D���� ����
            maxSumFromPrevIndexToLeft = temporary;
        }
        // �ִ� ���� ��, �ִ� �� ����
        finalAnswer = max(finalAnswer, maxSumFromPrevIndexToLeft);
    }
    
    return finalAnswer;
    
}


// �־��� �ش信��, �����θ� �̷���� �迭�� �Ÿ��� �ʰ� �ѹ��� �� ó���ϴ� ���
int another_maxSumSubarray(vector<int> A) {
    
    // ū ���� ���� �ٲپ�� �ϹǷ� �ּ� ���� �ִ´�
    int maxSumFromPrevIndexToLeft = INT_MIN;
    int finalAnswer = INT_MIN;

    int arraySize = A.size();
    for (int i = 0; i < arraySize; i++) {

        // ������ ���̳ʽ� => Ȯ���� ���� �ʿ䰡 ���� => ���� ���� ������ ����
        if (maxSumFromPrevIndexToLeft < 0) {
            // ���� ���� ����Ѵ�, ���� ��ġ�� ���� �������� �缳��
            maxSumFromPrevIndexToLeft = A[i];
        }
        else {
            // ���� �þ���� �ְ�
            // ���� �پ����� �� ������ ������ �� ������
            // �ϴ� ���Ѵ�
            maxSumFromPrevIndexToLeft += A[i];
        }
        // �ִ� ���� ��, �ִ� �� ����
        finalAnswer = max(finalAnswer, maxSumFromPrevIndexToLeft);
    }

    return finalAnswer;
}