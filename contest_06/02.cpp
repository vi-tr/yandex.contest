#include<iostream>
#include<string>
#include<map>

std::map<std::string, double> bonuses;

// cut
class Employee {
    public:
    std::string name; std::string occupation; int money;
    Employee(std::string n, std::string o, int m) {
          name = n; occupation = o; money = m;
    }
    int bonus(double b) {
        return (int)(money*b+0.5);
    }
    int salary() {
        return money+bonus(bonuses[occupation]);
    }
};
std::ostream& operator<<(std::ostream& out, Employee a){
    out << a.name << " (" << a.occupation << "): " << a.salary();
    return out;
}

class Manager: public Employee {
    public:
    Manager(std::string name, int money = 16242): Employee(name,"manager",money) {}
    int salary() {
        return money+bonus(bonuses[occupation]<0.1?0.1:bonuses[occupation]);
    }
};
std::ostream& operator<<(std::ostream& out, Manager a){
    out << a.name << " (" << a.occupation << "): " << a.Manager::salary();
    return out;
}
// cut

class Boss: public Employee{
public:
    Boss(std::string name, int money = 16242)
    :Employee(name, "boss", money){}
};

int main(){
    double boss_bonus, manager_bonus;
    std::cin >> boss_bonus >> manager_bonus;
    bonuses["manager"] = manager_bonus;
    bonuses["boss"] = boss_bonus;

    int john_money, bob_money, alice_money;
    std::cin >> john_money >> bob_money >> alice_money;
    Boss john("John", john_money);
    Manager bob("Bob", bob_money);
    Manager alice("Alice", alice_money);

    std::cout << john << '\n' << bob << '\n' << alice << std::endl;
}
