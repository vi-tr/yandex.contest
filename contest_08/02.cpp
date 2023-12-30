#include <iostream>

// cut
class Vector {
    public:
        int x, y;
        Vector(long double x,long double y):x(x),y(y){}
        Vector(Vector start, Vector end):x(end.x-start.x),y(end.y-start.y){}
        Vector* move(Vector by) {
            x+=by.x; y+=by.y;
            return this;
        }
};
typedef Vector Point;
// cut

int main(){
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    Point p(x1, y1);
    Vector dir(Point(x2, y2), Point(x3, y3));
    p.move(dir);
    
    std::cout << p.x << ' ' << p.y;
}
