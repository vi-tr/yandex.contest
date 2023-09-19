#include <iostream>

struct Complex{
  double re;  // Действительная часть
  double im;  // Мнимая часть
};

//--- cut here

Complex make_complex(std::string num) {
    Complex ans;
    // ah yiss lexing
    bool started_re = false;
    bool started_im = false;
    std::string re = "";
    std::string im = "";

    for (char& c : num) {
        if ((c == ' ') || (c == 'j')) {
            continue;
        } else if ((c == '-') || (c == '+')) {
            if (started_re) {
                started_im = true;
                if (c == '-') {
                    im.append(1, c);
                }
            } else {
                started_re = true;
                if (c == '-') {
                    re.append(1, c);
                }
            }
        } else {
            if (started_im) {
                im.append(1, c);
            } else {
                re.append(1, c);
                if (!started_re) {
                    started_re = true;
                }
            }
        }
    }

    ans.re = std::stod(re);
    ans.im = std::stod(im);
    return ans;
}

Complex sum(Complex x, Complex y) {
    Complex ans;
    ans.re = x.re + y.re;
    ans.im = x.im + y.im;
    return ans;
}

Complex sub(Complex x, Complex y) {
    Complex ans;
    ans.re = x.re - y.re;
    ans.im = x.im - y.im;
    return ans;
}

Complex mul(Complex x, Complex y) {
    Complex ans;
    ans.re = x.re*y.re - x.im*y.im;
    ans.im = x.re*y.im + x.im*y.re;
    return ans;
}

Complex div(Complex x, Complex y) {
    Complex ans;
    ans.re = (x.re*y.re + x.im*y.im)/(y.re*y.re + y.im*y.im);
    ans.im = (x.im*y.re - x.re*y.im)/(y.re*y.re + y.im*y.im);
    return ans;
}

void print(Complex a) {
    std::cout << a.re << (a.im >= 0 ? "+" : "") << a.im << "j" << std::endl;
}

//---

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);
    
    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));
}
