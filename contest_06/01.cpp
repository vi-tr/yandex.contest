#include <iostream>
#include <vector>

// cut
class Shape {
    public:
        std::vector<double> points{};
        double getPerimeter() {
            double sum = 0; for (const double p : points) sum+=p;
            return sum;
        }   
};
class Triangle : public Shape {
    public:
    Triangle(int a, int b, int c) {
        if ((a+b>c) && (a+c>b) && (c+b>a)) { 
            points.push_back(a);
            points.push_back(b);
            points.push_back(c);
        }
        points.push_back(0);
    }
};
class Rectangle : public Shape {
    public:
    Rectangle(int a, int b) {
        points.push_back(a); points.push_back(a);
        points.push_back(b); points.push_back(b);
    }
};

class Circle : public Shape {
    public:
    Circle(int r) {
        points.push_back(((double)r * 6.283185307));
    }
};
// cut

int main(){
    int momentum;
    std::cin >> momentum;
    srand(momentum);
    std::vector <Shape*> shapes(rand() % 100 + 1);
    for (int i=0; i < shapes.size(); i++){
        int a = rand()%10 + 1, b = rand()%10 + 1, c = rand()%10 + 1;
        if (rand() % 3 == 0) shapes[i] = new Rectangle(a, b);
        else if (rand() % 3 == 1) shapes[i] = new Circle(c);
        else shapes[i] = new Triangle(a, b, c);
    }
    
    double sum = 0;
    for (auto shape : shapes) { sum += shape->getPerimeter();}
    std::cout << (int)sum;
}
