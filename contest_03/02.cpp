#include <iostream>
#include <vector>

using namespace std;

int main() {
    char x;
    vector<char> stack;
    cin >> x;
    while (x != '!') {
        switch (x) {
            case '(':
                stack.push_back(')');
                break;
            case '{':
                stack.push_back('}');
                break;
            case '[':
                stack.push_back(']');
                break;
            case ')': case '}': case ']':
                if (stack[stack.size()-1] == x) {
                    stack.pop_back();
                } else {
                    cout << "NO";
                    return 0;
                }
                break;
        }
        cin >> x;
    }

    cout << (stack.size() == 0 ? "YES" : "NO");

    return 0;
}
