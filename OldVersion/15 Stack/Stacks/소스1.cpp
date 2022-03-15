#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool duplicateParentheses(string str) {
    stack<char> s{};

    for (auto x : str) {
        if (x == '(') s.push(x);
        else if (x == ')') s.pop();
    }

    return s.empty();
}

int main() {
    string str{ "(a+b)" };
    cout << duplicateParentheses(str) << endl;
}