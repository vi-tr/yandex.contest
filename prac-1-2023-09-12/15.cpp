#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int tally = 1;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i-1]) {
            tally += 1;
        } else {
            if (tally == 1) {
                cout << str[i-1];
            } else {
                cout << str[i-1] << tally;
            }
            tally = 1;
        }
    }

    if (tally == 1) {
        cout << str[str.length()-1] << endl;
    } else {
        cout << str[str.length()-1] << tally << endl;
    }
    return 0;
}
