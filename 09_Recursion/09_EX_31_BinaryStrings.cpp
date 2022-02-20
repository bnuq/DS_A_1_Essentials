/*
�־��� �ڸ� ���� ������ ��� ������ ǥ���� ã�Ƽ� ����,
�׷��� 1�� �����ϸ� �ȵǰ� vector<string> �� ��Ƽ� ����
*/
//Expected Time Complexity: O(2^n)

#include <iostream>
#include <vector>
#include <string>
using namespace std;


// ���� ���� ���� => �� recursion ���� vector<string> �� ����
// ���� sub problem �� �ذ��� ����� vector<string> �� �ް��� => �װ� ���� �̹� �ܰ� �ذ� => ���ο� vector<string> �� �����Ѵ�
// �� �κ��� sub problem �� �ذ��ߴ� �����ϰ� => �̹� �ܰ� �ذ�
vector<string> makeBinaryStrings(int i, int n) { // i ��° �ڸ� ����, �� n �ڸ�
    vector<string> res{};
    if (i == 1) { // Base Case
        res.push_back("0");
        res.push_back("1");
        return res;
    }
    else {
        // sub problem ���� �ذ� => �ذ��� ����� vector �� �޴´�
        vector<string> vec = makeBinaryStrings(i - 1, n);

        // ���� �ܰ� �۾�
        for (const auto& x : vec) {
            if (x.back() == '0') {
                res.push_back(x + "0");
                res.push_back(x + "1");
            }
            else res.push_back(x + "0");
        }

        return res;
    }
}



/*
�ؼ� ���� => ���ϴ� ������ ���� string �� �ϳ��ϳ� ã�ư��� ����
recursion �� ���ؼ�, ���ϴ� ������ ���ڿ��� ����� ������ ���� => �����ϸ� �ְ�, ���� ������ �׳� return �Ѵ�
����� �� ����� �Ű�, ���� �� ������ �� �ٸ� ����
*/
vector<string> v; // ���� ����� ��� ���� => ���� ������ ����
void helper(string givenStr,int n,int i){
    if(i==n){   // ���ϴ� �ڸ����� �� ä������, ���� ���Ϳ� ����
        v.push_back(givenStr);
        return;
    }

    string newStr{ givenStr }; // �̹��� �۾��ϰ��� �ϴ� ���ڿ� => �ϴ� �տ��� ���� ���ڿ��� �����´�
    newStr.push_back('0'); // ���� string ���¿� ������� 0 �� �׻� ���� �� �ִ�
    helper(newStr,n,i+1);  // 0 �� ���̰� ���� ������ ��츦 ��� ã�´�


    // ���� �־��� string �� 1 �� ���� �� �ִ� �� ���� �� Ȯ��
    if(i>0 && givenStr.back()=='0'){ // ���ڸ��� 0 �� ��� => ���� �� �ִ�
       givenStr.push_back('1');
       helper(givenStr,n,i+1);
    }
    else if(i==0){ // �ƴϸ� �ƿ� ù�ڸ��� ���
        givenStr.push_back('1');
        helper(givenStr,n,i+1);
    }
    // 1 �� ���� �� ���� ��� => ���ٸ� �۾� ���� ����
    return;
}
vector<string> binaryStrings(int n){
     v.clear();
     string str;
     helper(str,n,0);
     return v;

}

int main() {
    vector<string> vec1{ makeBinaryStrings(4, 4) };
    for (const auto& x : vec1)
        cout << x << endl;

    cout << endl << endl;

    vector<string> vec2{ binaryStrings(4) };
    for (const auto& x : vec2)
        cout << x << endl;
}