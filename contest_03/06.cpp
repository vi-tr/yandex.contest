#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int len;
    cin >> len;
    map<string, long int> users;
    for (int i = 0; i<len; i++) {
        string temp;
        cin >> temp;
        string login = temp.substr(0, temp.find(";"));
        long int balance = stol(temp.substr(temp.find(";")+1,temp.length()-1));
        users[login] = balance;
    }

    cin >> len;
    for (int i = 0; i<len; i++) {
        string temp;
        cin >> temp;
        cout << users[temp] << " ";
    }

    return 0;
}
