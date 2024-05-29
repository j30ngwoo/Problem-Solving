#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '(') return 3;
    return 0;
}

int main() {
    string s;
    stack<char> stk;

    cin >> s;
    
    for (char c : s) {
        if (isalpha(c)) {
            cout << c;
        } else if (c == '(') {
            stk.push(c);
        } else if (c == ')') {
            while (stk.top() != '(') {
                cout << stk.top();
                stk.pop();
            }
			stk.pop();
        } else {
            while (!(stk.empty() || stk.top() == '(' || precedence(c) > precedence(stk.top()))) {
                cout << stk.top();
                stk.pop();
            }
			stk.push(c);
        }
    }
    
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    
    return 0;
}
