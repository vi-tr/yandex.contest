#include <iostream>
#include <tuple>

//--- cut here

#include <numeric>

std::tuple<int, int, int> find_lcm(int x, int y) {
    int z = std::lcm(x, y);
    return std::make_tuple(z, z/x, z/y);
}

std::tuple<int, int> reduce(int x, int y) {
    int z = std::gcd(x, y);
    return std::make_tuple(x/z, y/z);
}

//---

int main() {
    int m1, n1, m2, n2;
    char _;
    std::cin >> m1 >> _ >> n1
             >> m2 >> _ >> n2;
    std::tie(m1, n1) = reduce(m1, n1);
    std::tie(m2, n2) = reduce(m2, n2);

    auto[lcm, c1, c2] = find_lcm(n1, n2);
    auto[m, n] = reduce(m1 * c1 + m2 * c2, lcm);

    std::cout << m << '/' << n << std::endl;
}
