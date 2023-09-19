#include <iostream>

bool is_prime(int n) {
    if (((n % 2 == 0) && (n != 2)) || ((n % 3 == 0) && (n != 3))) {
        return false;
    }

    for (int k = 1; 36*k*k-12*k < n; ++k) {
        if ((n % (6*k+1) == 0) || (n % (6*k-1) == 0)) {
            return false;
        }
    }
    return true;
}

int main(){
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}
