#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double m, h;
    
    cin >> m >> h;
    cout << setprecision(30) << m/(h*h) << endl;

    return 0;
}
