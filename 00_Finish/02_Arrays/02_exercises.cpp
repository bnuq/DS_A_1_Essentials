#include <iostream>
#include <vector>
using namespace std;

/* 2.
* ������ �����ϴ� ������ �迭, sub array sum �� �ִ밪�� ���ϰ� �ʹ�
* Expected Time Complexity: O(N), Hint: Kadane's Algorithm
*/
int my_maxSumSubarray(vector<int> A) {
    // �����θ� �̷���� �迭�� �־��� �� �ִ� => largest sum �� ������ �� ���� �ִ�
    // ���� maximum sum �� �ּҰ����� �ʱ�ȭ �Ѵ�
    int curSum{ 0 }, maxSum{ INT_MIN };

    for (int i = 0; i < A.size(); i++)
    {
        // ���� ���Ҹ� �����ϴ� ���� ���� ���Ѵ�
        curSum += A[i];

        // �������� �ٸ���, maximum sum �� ������ �� �����Ƿ� ���� ���� ���� �հ� ������� �ִ� ���� ���Ѵ�
        if (curSum > maxSum) maxSum = curSum;

        // ���� ���� ������ ���, �� ���� �ִ� ���̿��� ������ ���� ���ϴ� ���� ������ �ȵȴ�
        // �׷��ϱ� ������� ���� �������, ������ �ڸ����� �Ѵ�
        // ������ ��� ȥ�ڼ� ������ �̷絵�� �Ѵ�
        if (curSum < 0) curSum = 0;
    }

    return maxSum;
}
int another_maxSumSubarray(vector<int> A) {
    int maxSumFromPrevIndexToLeft = INT_MIN; // ���������� ��
    int finalAnswer = INT_MIN;               // ���������� ���ϴ� �ִ� ��

    for (int i = 0; i < A.size(); i++) {
        // ���� ���� ���� ���̳ʽ� => �̹� ������ ���Խ�ų �ʿ� ����
        if (maxSumFromPrevIndexToLeft < 0) {
            // ���� ���� ������ ���ο� ������ �����, ���� ��ġ�� ���� �������� �缳��
            maxSumFromPrevIndexToLeft = A[i];
        }
        else {
            // ���� ���� ���� �÷��� ���ٸ�, �̹� ��� ���� ������� ��·�� ������ �Ǵ� ���
            // �̹� ���� ���� ���� ������ ���Խ�Ų��
            maxSumFromPrevIndexToLeft += A[i];
        }
        // �ִ� ���� ��, �ִ� �� ����
        finalAnswer = max(finalAnswer, maxSumFromPrevIndexToLeft);
    }
    return finalAnswer;
}

/*3.
* sorted array �� �־��� ��, �迭���� � Val �� lower bound ���� ���϶�
* If Val is not present in array, then lower bound of the Val means an integer which is just smaller than given integer
* Otherwise, Val itself is the answer
* binary search �� Ȱ������
*/
int lowerBound(vector<int> A, int Val) {
    int sz = A.size();
    // Ž�� ���� => �ε����� ǥ��
    int l = 0, r = (sz - 1);
    int answer = -1;
    
    // ������ ���� �������� ������ => ������ ���� ��ġ�� ��߳��� �ȴ�
    while (l <= r) {
        // �߰� ��ġ�� ���Ѵ� => l ~ mid ~ r
        int mid = (l + r) / 2;

        // lower bound �� l ~ mid ���̿� �ִ��� Ȯ��
        if (A[mid] > Val) { // non-decreasing ���� ���ĵƴ� �����ϱ� ������
            // r ��ġ ����
            r = mid - 1;
        }
        // mid <= < r ���̿� ���� ��
        else {
            // lower bound => �ϴ� Val ���� �����Ƿ� ���ɼ��� �����Ѵ�
            // �ϴ� mid ��ġ = answer
            answer = A[mid];
            // ���ο� ������ �ٽ� ����
            l = mid + 1;
        }
    }
    return answer;
}

/*
* sorted array �� �־���, �迭 ��ҵ� ��, �� ���� x �� ���� ����� pair �� ã�ƶ�
*/
pair<int, int> closestSum(vector<int> arr, int x) {
    // ������ �迭 �ε����� �����ϴ� ����
    int res_l, res_r;
    int n = arr.size();

    // �˻� ������ ��Ÿ���� �ε���, �迭�� �� ���ʰ� �������� ����Ŵ, ������ ������ ������
    // �迭�� �̹� ���ĵǾ� �ִٴ� ���� �̿� => ���� x �� ��������� �ϱ� ���ؼ� �� ū ���� ���ϰų� �� ���� ���� ���ϰ� �Ѵ�
    int l = 0, r = n - 1, diff = INT_MAX;

    // ���� ��߳� ������ �ݺ�
    while (r > l) {
        // �� - �� �� �ּҰ� �ɶ�
        if (abs(arr[l] + arr[r] - x) < diff) {
            // ���� ����
            res_l = l;
            res_r = r;
            diff = abs(arr[l] + arr[r] - x);
        }
        // ���� ũ�ٸ� �ٿ��� �ϴϱ�, ū ���� �ű��
        if (arr[l] + arr[r] > x)
            r--;
        // �۴ٸ� ���� ���� �ű��
        else l++;
    }
    // �̰ɷ� pair �� ���� �� �ִ� ~ �ű�
    return { arr[res_l], arr[res_r] };
}