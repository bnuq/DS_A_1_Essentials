#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> my_intersection(vector<int>& nums1, vector<int>& nums2) {

    unordered_set<int> setFor1{};
    set<int> finalSet{};

    for (const int& i : nums1) {
        setFor1.insert(i);
    }

    for (const int& i : nums2) {
        //ã�� => ��ģ�� => �ִ´�
        if (setFor1.find(i) != setFor1.end()) {
            finalSet.insert(i);
        }
    }

    vector<int> res{};
    for (const int& i : finalSet) {
        res.push_back(i);
    }

    return res;
}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    //unordered map �� ����ϳ�
    unordered_map<int, int> map;
    vector<int> result;

    for (int i = 0; i < nums1.size(); i++) {
        /*
            map �� [] operator ���
            �ش� key ��尡 �������� ������, �ڵ����� �ϳ� �������ش�
            
            ã�ų�, ������ ������
            ���� 1�� ������Ű��
        */        
        map[nums1[i]]++;
    }

    for (int i = 0; i < nums2.size(); i++) {
        /*
            [] operator ���, ������ �ϳ� ����
            �ٵ� ���� Ȯ�� => ���� �����ϴ� ���, �̹� �ִ� ��쿡 ���ؼ���
            �߰� ó�� => intersection �̴ϱ�
        */
        if (map[nums2[i]] > 0) {
            result.push_back(nums2[i]);
            map[nums2[i]] = 0;
        }
    }

    //vector ����
    sort(result.begin(), result.end());
    
    return result;
}

int main() {
    vector<int> nums1{ 1,2,3,1,2,3,45,5,3 };
    vector<int> nums2{ 3,2,2,2,1,2,2,1,9 };

    vector<int> res = intersection(nums1, nums2);

    for (auto x : res) {
        cout << x << endl;
    }
}