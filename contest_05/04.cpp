#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// cut
#include <cmath>

class Point {
    double x;
    double y;
    public:
        Point(double sx, double sy) {
            x = sx;
            y = sy;
        }
        double get_x() { return x; }
        void set_x(double nx) { x = nx; }
        double get_y() { return y; }
        void set_y(double ny) { y = ny; }
        double get_r() {
            return sqrt(x*x + y*y);
        }
        void set_r(double r) {
            double a = get_a();
            x = r*cos(a);
            y = r*sin(a);
        }
        double get_a() {
            return atan2(y,x);
        }
        void set_a(double a) {
            double r = get_r();
            x = r*cos(a);
            y = r*sin(a);
        }
};

// cut

int main(){
    double x, y;
    std::cin >> x >> y;

    Point p(x, y);
    json moves;
    std::cin >> moves;
    
    for(auto& move : moves){
        std::string ort = move["ort"];
        double value = move["value"];
        if (ort == "x") p.set_x(p.get_x() + value);
        else if (ort == "y") p.set_y(p.get_y() + value);
        else if (ort == "r") p.set_r(p.get_r() + value);
        else p.set_a(p.get_a() + value);
        std::cout << round(p.get_x()*(1E+5))/(1E+5) << ' ' << round(p.get_y()*(1E+5))/(1E+5) << std::endl;    
    }
}
