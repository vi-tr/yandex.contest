#include <iostream>

// cut
class IntSharedPointer {
    public:
    int* RC;
    int* theS;
    void dec() {
        *RC -= 1;
        if (*RC == 0) {
            delete theS;
            delete RC;
        }
    }
    void inc(const IntSharedPointer& b) {
        theS = b.theS;
        RC = b.RC;
        *RC += 1;
    }
    IntSharedPointer(int* s) { RC = new int{1}; theS = s; }
    IntSharedPointer(IntSharedPointer& b) { inc(b); }
    ~IntSharedPointer() { dec(); }
    int& operator*() { return *theS; }
    IntSharedPointer& operator=(const IntSharedPointer& b) {
        if (this == &b) return *this;
        dec(); inc(b); return *this;
    }
};
// cut

void print(IntSharedPointer p){
    std::cout << *p << std::endl;
}

void print_with_exception(IntSharedPointer p){
    std::cout << *p << std::endl;
    if (*p % 2) throw std::string("error");
}

int main(){
    IntSharedPointer p(new int);
    std::cin >> *p;
    p = p;
    print(p);

    IntSharedPointer p2(p);
    std::cin >> *p2;
    print(p);
    print(p2);
    
    {
        int value;
        std::cin >> value;
        IntSharedPointer p3(new int(value));
        p2 = p3;
    }
    print(p2);
    
    p = p2;
    try{
        print_with_exception(p);
    }
    catch (const std::string& e) {
        std::cout << e << std::endl;
    }
}
