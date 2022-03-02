#include <vector>
#include <queue>
#include <iostream>
using namespace std;



vector<char> firstnonrepeating(vector<char> str) {

    vector<char> res{};
    vector<int> isUnique(CHAR_MAX, 0);

    queue<char> q{};

    for (auto ch : str) {
        if (isUnique[ch - 'a'] == 0) { // ���� �ѹ��� �ȳ��Դ�
            isUnique[ch - 'a'] = 1;
            q.push(ch);
            res.push_back(q.front());
        }
        else { // �̹� ���Ծ��� ����
            // ó������ �ߺ��Ǵ� ���
            if (isUnique[ch - 'a'] == 1) isUnique[ch - 'a']++; // ���� 2�� ����� => 2��° ���Դ�
            // ť�� �߰����� �ʰ�

            // Ȥ�� ť�� ����ٸ� 0 ���
            if (q.empty()) res.push_back('0');
            else {
                // Ȥ�� ť ����Ʈ�� ���� �� Ȯ��
                if (q.front() == ch) {
                    q.pop();

                    while (!q.empty() and isUnique[q.front() - 'a'] == 2) {
                        q.pop();
                    }

                    if (q.empty()) res.push_back('0');
                    else res.push_back(q.front());
                }
                else {
                    res.push_back(q.front());
                }
            }            
        }
    }

    return res;
}

int main() {
    vector<char> str{'a', 'a', 'b', 'c'};

    vector<char> res = firstnonrepeating(str);

    for (auto x : res)
        cout << x << " ";
    cout << endl;
}