#include <iostream>
#include <string>

// cut

class Complex {
    public:
        long double re;
        long double im;
        Complex(std::string num) {
            bool started_re = false;
            bool started_im = false;
            std::string tre = "";
            std::string tim = "";

            for (char& c : num) {
                if ((c == ' ') || (c == 'j')) {
                    continue;
                } else if ((c == '-') || (c == '+')) {
                    if (started_re) {
                        started_im = true;
                        if (c == '-') {
                            tim.append(1, c);
                        }
                    } else {
                        started_re = true;
                        if (c == '-') {
                            tre.append(1, c);
                        }
                    }
                } else {
                    if (started_im) {
                        tim.append(1, c);
                    } else {
                        tre.append(1, c);
                        if (!started_re) {
                            started_re = true;
                        }
                    }
                }
            }

            re = std::stod(tre);
            im = std::stod(tim);
            re = re == 0.0 ? 0.0 : re;
            im = im == 0.0 ? 0.0 : im;
        }
        Complex operator+(Complex y) {
            Complex ans("0+0");
            ans.re = re + y.re;
            ans.im = im + y.im;
            return ans;
        }
        Complex operator-(Complex y) {
            Complex ans("0+0");
            ans.re = re - y.re;
            ans.im = im - y.im;
            return ans;
        }
        Complex operator*(Complex y) {
            Complex ans("0+0");
            ans.re = re*y.re - im*y.im;
            ans.im = re*y.im + im*y.re;
            return ans;
        }
        Complex operator/(Complex y) {
            Complex ans("0+0");
            ans.re = (re*y.re + im*y.im)/(y.re*y.re + y.im*y.im);
            ans.im = (im*y.re - re*y.im)/(y.re*y.re + y.im*y.im);
            return ans;
        }
};

std::ostream& operator<<(std::ostream& out, const Complex& a){
    out << (a.re==0.0 ? 0.0 : a.re) << (a.im >= 0 ? "+" : "") << (a.im==0.0 ? 0.0 : a.im) << "j";
    return out;
}

// cut

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2(num);
    
    std::cout << c1+c2 << '\n' << c1-c2 << '\n'
              << c1*c2 << '\n' << c1/c2 << std::endl;
}
