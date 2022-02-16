#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 12.
string compression ����
*/
int my2_compress(vector<char>& chars) {
    string s{};
    // �����ϴ� �����, index, iterator �������� �����ϴ� �ž�
    auto itr = chars.begin();
    for (itr = chars.begin(); itr < chars.end(); itr++) {
        int count{ 1 };
        // �ݺ��� �ȿ��� �ݺ��� => �� ���� �������� �� ��� �ϳ��� ó���� �ʿ�� ����
        // ���� ���ڵ��� �پ� �ִ� ��츦 ó���ϴ� �� => �ϳ��� �������� ó��
        while (itr < chars.end() - 1 && *itr == *(itr + 1)) {
            count++;
            itr++; // ���⼭ iterator �� �߰� ����
        }
        s += *itr;
        if (count != 1) {
            s += to_string(count);
        }
    }
    // vector :: clear() => vector �� ���� �ʱ�ȭ �ϴ� �޼���
    chars.clear();
    for (auto x : s) {
        chars.push_back(x);
    }
    return chars.size();
}

/* 14.
���ڿ� ������ �ߺ��Ǵ� ���ڸ� ��� �����϶�
*/
#include <set>
string removeDuplicate(string s) {
    // �̰� �ڷᱸ���� �̿��ϴ� �������
    // set �� �ִ´� => binary tree ����, �ߺ� keys �� ������� �ʴ´�, �ڵ� ����
    // iterator �� �̿��ؼ�, vector => set �� ���� �� �ִ�
    // iterator �� �̿��ؼ� �ʱ�ȭ �ϴ� ���
    set<char> ss(s.begin(), s.end());
    set<char> sss{ s.begin(), s.end() };

    // vector �ε� �����ϴ�
    vector<char> vec{ 'a', 'a', 'a', 'a', 'a', 'b', 'e', 'a', 'a'};
    set<char> ssss{ vec.begin(), vec.end() };

    string str;
    for (auto x : sss)
        str.push_back(x);

    for (auto x : ssss)
        cout << x << " , ";

    return str;
}

/* 15
aeiou �� string ���� �̾Ƴ���
*/
#include <algorithm>
string my_vowel(string S) {
    string res{};

    // for_each �˰��� �ѹ� ����� ����
    for_each(S.begin(), S.end(), [&res](const auto& e) {
        if (e == 'a' or e == 'e' or e == 'i' or e == 'o' or e == 'u')
            res += e;
        });
    return res;
}


int main() {
    string s{ "weklerklwmfwen" };
    cout << endl << removeDuplicate(s) << endl;
}