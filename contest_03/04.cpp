#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int len;
    cin >> len;
    vector<string> a(len);
    for (int i = 0; i < len; i++) {
        cin >> a[i];
    }
    cin >> len;
    vector<string> b(len);
    for (int i = 0; i < len; i++) {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<string> ans;
    set_intersection(a.begin(),a.end(),
                     b.begin(),b.end(),
                     back_inserter(ans));
    ans.erase(unique(ans.begin(),ans.end()), ans.end());

    if (ans.size() == 0) {
        cout << "-1";
        return 0;
    }

    for (int i = 0; i < ans.size()-1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1];

    return 0;
}
