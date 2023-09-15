#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long double a, b;
    cin >> a >> b;
    cout << setprecision(30) << a/b;
    return 0;
}
