#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

const string digits = "1234567890";
const string leftopts = "+-*/%";
int main() {
    char a;
    string input;
    bool prev_digit = true;
    string ans = "";
    stack<char> symbols;
    map<char, int> priorities = {
        {'+', 0},
        {'-', 0},
        {'*', 1},
        {'/', 1},
        {'%', 1},
        {'^', 2},
        {'(', -1}
    };

    cin >> input;
    for (char& a : input) {
        if (digits.find(a) != digits.npos) {
            if ((!prev_digit) && (ans.size()!=0))
                ans.append(1,' ');
            ans.append(1,a);
            prev_digit = true;
            continue;
        } else if (a == '(') {
            symbols.push('(');
        } else if (a == ')') {
            char temp = symbols.top();
            do {
                temp = symbols.top();
                if (temp != '(') {
                    ans.append(1,' ');
                    ans.append(1,temp);
                }
                symbols.pop();
            } while ( (!symbols.empty()) && (temp != '(') );
        } else if (a == '^') {
            symbols.push(a);
        } else {
            while ( (!symbols.empty()) && (priorities[a] <= priorities[symbols.top()]) ) {
                ans.append(1,' ');
                ans.append(1, symbols.top());
                symbols.pop();
            }
            symbols.push(a);
        }
        prev_digit = false;
    }
    while (!symbols.empty()) {
        ans.append(1,' ');
        ans.append(1,symbols.top());
        symbols.pop();
    }

    cout << ans;
    return 0;
}
