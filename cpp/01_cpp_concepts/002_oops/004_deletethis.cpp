#include <iostream>
class Person{
    public:
    int a;
    Person() : a{0} {
        std::cout<<"Constructor!\n";
    }
    void destroy() {
        delete this;
    }
    void print() {
        std::cout<<"Person\n";
    }
};

int main() {
    Person p;
    p.destroy();
    return 0;
}