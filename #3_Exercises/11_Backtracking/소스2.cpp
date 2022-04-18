#include <string>
#include <vector>
#include <iostream>
using namespace std;


int getPossibleWays(string& str, vector<string>& dict, int strInd, int dictInd) {
    if (strInd == str.size()) return 1;
    if (dictInd >= dict.size()) return 0;

    cout << "count" << strInd << " " << dictInd << endl;
    
    int curStrSize = dict[dictInd].size();
    int res{ 0 };
    bool flag{ true };
    for (int i = 0; i < curStrSize; i++) {
        if (str[strInd + i] != dict[dictInd][i]) {
            flag = false;
            cout << "Not same" << endl;
            break;
        }
    }
    if (flag) res += getPossibleWays(str, dict, strInd + curStrSize, dictInd + 1);

    res += getPossibleWays(str, dict, strInd, dictInd + 1);

    return res;
}


int wordBreak(string str, vector<string>& dictionary) {
    return getPossibleWays(str, dictionary, 0, 0);
}



int main() {
    string str{ "ilikesamsungmobile" };
    vector<string> dict{ "i", "like", "sam", "sung", "samsung", "mobile"};
    cout << wordBreak(str, dict) << endl;
}