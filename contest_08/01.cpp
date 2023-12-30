#include <iostream>

class Keeper{
    int trash;
    int secret;
    
public:
    Keeper(){
        std::cin >> secret;
    }
};

// cut
#define Keeper TheCoolerKeeper
class TheCoolerKeeper{
public:
    int trash;
    int secret;

    TheCoolerKeeper(){
        std::cin >> secret;
    }
};

int hack_it(TheCoolerKeeper o) {
    return o.secret;
}

// cut

int main(){
    Keeper keeper;
    int secret= hack_it(keeper);
    std::cout << secret;
}
