#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double acc;
    for (int i = 0; i < 6; i++) {
        acc += (-(i%2)*2+1)  *  pow((i*2+1)*pow(3,i),-1);
    }
    cout << acc*sqrt(12) << endl;
    return 0;
}
