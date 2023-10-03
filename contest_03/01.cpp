#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long int a;
    vector<long int> x;
    cin >> a;
    for (long int i = 0; i<a; i++) {
        long int temp;
        cin >> temp;
        x.push_back(temp);
    }
    cin >> a;
    for (long int i = 0; i<a; i++) {
        long int temp;
        cin >> temp;
        x.push_back(temp);
    }
    sort(x.begin(), x.end());

    for (int i = 0; i < x.size()-1; i++) {
        cout << x[i] << " ";
    }
    cout << x[x.size()-1];

    return 0;
}
