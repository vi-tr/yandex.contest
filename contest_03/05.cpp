#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int len;
    cin >> len;
    map<string, int> freq;
    for (int i = 0; i < len; i++) {
        string temp;
        cin >> temp;
        if (freq.find(temp) == freq.end()) {
            freq[temp] = 1;
        } else {
            freq[temp] += 1;
        }
    }

    int max_occurs = 0;
    for (const auto& [k, v] : freq) {
        if (v > max_occurs) {
            max_occurs = v;
        }
    }
    for (const auto& [k, v] : freq) {
        if (v == max_occurs) {
            cout << k << ' ';
        }
    }

    return 0;
}
