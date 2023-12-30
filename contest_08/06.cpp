#include <iostream>
#include <string>
#include <vector>

class Any{
    enum class Type{
        INT,
        DOUBLE,
        STRING,
        VECTOR_ANY_PTR
    };

    void* data;
    Type type;

public:
    Any(int* data);
    Any(double* data);
    Any(std::string* data);
    Any(std::vector<Any*>* data);
    ~Any();
    
    operator int();
    operator double();
    operator std::string();
    operator std::vector<Any*>*();

    friend std::ostream& operator<<(std::ostream& out, const Any& val);
};

std::ostream& operator<<(std::ostream& out, const Any& o);

int main(){
    Any data(new std::vector<Any*>());
    
    std::vector<Any*>* array = (std::vector<Any*>*)data;
    
    int ints_count;
    std::cin >> ints_count;
    for(int i=0; i<ints_count; i++){
        int value;
        std::cin >> value;
        Any* temp = new Any(new int(value));
        array->push_back(temp);
    }
    
    int doubles_count;
    std::cin >> doubles_count;
    for(int i=0; i<doubles_count; i++){
        double value;
        std::cin >> value;
        Any* temp = new Any(new double(value));
        array->push_back(temp);
    }

    int strings_count;
    std::cin >> strings_count;
    for(int i=0; i<strings_count; i++){
        std::string value;
        std::cin >> value;
        Any* temp = new Any(new std::string(value));
        array->push_back(temp);
    }
    
    int i = 0; double d = 0; std::string s = "";
    for(auto value: *array){
        try{ i += (int)(*value); }
        catch(...){ }
        
        try{ d += (double)(*value); }
        catch(...){ }
        
        try{ s += (std::string)(*value); }
        catch(...){ }
    }
    
    Any ai(new int(i));
    Any ad(new double(d));
    Any as(new std::string(s));
    
    std::cout << data << "\n" << ai << ' ' << ad <<  ' ' << as;
}

// cut
Any::Any(int* x)               { type = Type::INT;            data = x; }
Any::Any(double* x)            { type = Type::DOUBLE;         data = x; }
Any::Any(std::string* x)       { type = Type::STRING;         data = x; }
Any::Any(std::vector<Any*>* x) { type = Type::VECTOR_ANY_PTR; data = x; }

Any::~Any() {
    switch (type) {
        case Type::INT: {
            int *p = static_cast<int*>(data);
            delete p;
            break;
        }
        case Type::DOUBLE: {
            double *p = static_cast<double*>(data);
            delete p;
            break;
        }
        case Type::STRING: {
            std::string *p = static_cast<std::string*>(data);
            delete p;
            break;
        }
        case Type::VECTOR_ANY_PTR: {
            std::vector<Any*> *p = static_cast<std::vector<Any*>*>(data);
            for (auto &j : *p) delete j;
            delete p;
            break;
        }
    }
}

Any::operator int() {
    if (type != Type::INT) throw 0;
    return *static_cast<int*>(data);
}
Any::operator double() {
    if (type != Type::DOUBLE) throw 0;
    return *static_cast<double*>(data);
}
Any::operator std::string() {
    if (type != Type::STRING) throw 0;
    return *static_cast<std::string*>(data);
}
Any::operator std::vector<Any*>*() {
    if (type != Type::VECTOR_ANY_PTR) throw 0;
    return static_cast<std::vector<Any*>*>(data);
}

std::ostream& operator<<(std::ostream& out, const Any& y) {
    switch (y.type) {
        case Any::Type::DOUBLE: {
            double *p = static_cast<double*>(y.data); out << *p;
            break;
        }
        case Any::Type::STRING: {
            std::string *p = static_cast<std::string*>(y.data); out << *p;
            break;
        }
        case Any::Type::INT: {
            int *p = static_cast<int*>(y.data); out << *p;
            break;
        }
        case Any::Type::VECTOR_ANY_PTR: {
            std::vector<Any*> *p = static_cast<std::vector<Any*>*>(y.data);
            for (auto &j : *p) out << *j << " ";
            break;
        }
    }
    return out;
}
