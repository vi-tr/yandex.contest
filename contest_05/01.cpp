#include <iostream>
// cut
#include <cstdlib>

class Cat {
    private:
        bool status;
    public:
        Cat() {
            status = std::rand() >= RAND_MAX/2;
        }
        bool is_alive() {
            return status;
        }
};

class Box {
    private:
        bool opened;
        Cat inside;
    public:
        Cat open() {
            if (!opened) {
                Cat newcat;
                inside = newcat;
                opened = true;
            }
            return inside;
        }
};

// cut

int main() {
 
    Box box;
    Cat cat = box.open();
    if (cat.is_alive()) std::cout << "alive";
    else std::cout << "dead";

    return 0;
}
