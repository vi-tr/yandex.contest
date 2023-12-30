#include <iostream>
#include <string>

// cut
#include <algorithm>
#include <vector>
typedef unsigned long long int LONG;

class Bigint {
    inline int abs(int x) { return x<0 ? -x : x; }
    inline int modulo(int x, int y) { return (x%y + y) % y; }
    // round towards negative inifinity
    inline int intdiv(int x, int y) { return x/y - (x%y != 0 && x < 0); }
    public:
        char sign = 1;
        std::vector<char> nums{0};
        Bigint() {}
        Bigint(int input) {
            if (input == 0) return;
            nums.pop_back();
            sign = input < 0 ? -1 : 1;
            while (input > 0) {
                nums.push_back(input % 10);
                input /= 10;
            }
        }
        Bigint(std::string input) {
            nums.pop_back();
            bool negative = input.at(0)=='-';
            if (negative) sign = -1;
            for (LONG i = negative; i < input.size(); i++)
                nums.push_back(input.at(i)-'0');
            std::reverse(nums.begin(), nums.end());
        }
        Bigint operator+(const Bigint y) {
            char sx = sign; char sy = y.sign;
            Bigint tx = *this; Bigint ty = y;
            tx.sign = ty.sign = 1;
            Bigint bigger; Bigint smaller;
            char flip = 1;
            if (tx < ty) {
                smaller = tx; bigger = ty;
                if (sx==1) flip = sy;
            } else {
                bigger = tx; smaller = ty;
                if (sy==1) flip = sx;
            }

            LONG i = 0; char carry = 0; Bigint result; result.nums.pop_back();
            while (i < bigger.nums.size() || i < smaller.nums.size() || carry != 0) {
                char sum = carry;
                if (i <  bigger.nums.size()) sum +=  bigger.nums[i];
                if (i < smaller.nums.size()) sum += smaller.nums[i] * sx * sy;

                result.nums.push_back(modulo(sum,10));
                carry = intdiv(sum,10);
                i++;
            }
            result.sign = sx == sy ? sx : flip;
            while (result.nums[result.nums.size()-1] == 0 && result.nums.size() > 1)
                result.nums.pop_back();
            return result;
        }
        Bigint operator-(const Bigint y) {
            Bigint temp = y; temp.sign *= -1;
            return (*this) + temp;
        }
        Bigint operator*(const Bigint y) {
            Bigint ans; Bigint tx = *this; Bigint ty = y;
            tx.sign = ty.sign = 1;

            for (LONG i = 0; i < tx.nums.size(); i++) {
                LONG j = 0; long int carry = 0; Bigint temp; temp.nums.pop_back();
                while (j < ty.nums.size() || carry != 0) {
                    long int prod = carry;
                    if (j < ty.nums.size()) prod += ty.nums[j] * tx.nums[i];
                    
                    temp.nums.push_back(modulo(prod,10));
                    carry = intdiv(prod,10);
                    j++;
                }
                for (LONG j = 0; j < i; j++) temp.nums.insert(temp.nums.begin(), 0);
                ans = ans + temp;
            }

            ans.sign = sign * y.sign;
            return ans;
        }
        Bigint operator/(const Bigint y) {
            Bigint ans; Bigint tx = *this; Bigint ty = y;
            tx.sign = ty.sign = 1;
            while (tx.sign == 1) {
                tx = tx - ty;
                ans = ans + Bigint(1);
            }
            ans = ans - Bigint(1);
            ans.sign = sign * y.sign;
            return ans;
        }
        bool operator==(const Bigint y) {
            if (nums.size() != y.nums.size()) return false;
            for (LONG i = 0; i < nums.size(); i++)
                if (nums[i] != y.nums[i]) return false;
            return sign == y.sign;
        }
        bool operator<(const Bigint y) {
            if (*this == y) return false;
            if (sign < y.sign) return true;
            if (sign > y.sign) return false;
            if (nums.size() < y.nums.size()) return true;
            if (nums.size() > y.nums.size()) return false;
            LONG i = nums.size()-1;
            while (nums[i] == y.nums[i]) i--;
            return nums[i] <  y.nums[i];
        }
        bool operator>(Bigint y) {
            return !(*this < y || *this == y);
        }
};

std::ostream& operator<<(std::ostream& out, const Bigint& a){
    out << (a.sign == -1 && !(Bigint(0)==a)?"-":"");
    for (LONG i = a.nums.size()-1; i > 0; i--)
        out << (char)(a.nums[i]+'0');
    out << (char)(a.nums[0]+'0');
    return out;
}

// cut

int main() {
    std::string a, b;
    std::cin >> a >> b;

    Bigint first(a);
    Bigint second(b);

    std::cout << "a + b = " << (first + second) << std::endl;
    std::cout << "a - b = " << (first - second) << std::endl;
    std::cout << "a * b = " << (first * second) << std::endl;
    std::cout << "a / b = " << (first / second) << std::endl;

    int c;
    std::cin >> c;
    Bigint third(c);
    Bigint zero;

    std::cout << "с > 0 = " << (third > zero) << std::endl;
    std::cout << "с < 0 = " << (third < zero) << std::endl;
    std::cout << "с == 0 = " << (third == zero) << std::endl;
}
