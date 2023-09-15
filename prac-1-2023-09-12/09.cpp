#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    cout << setprecision(30) << sqrt(a*a+b*b) << endl;
    return 0;
}
