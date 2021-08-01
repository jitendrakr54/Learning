// Object slicing can be prevented by making the base class function pure virtual there by disallowing object
// creation. It is not possible to create the object of a class which contains a pure virtual method.

#include <iostream>

class Base {
    public:
        virtual void print() = 0; // This can prevent object slicing as now it won't be possible to crate object of Base.
        // virtual void print()  { std::cout<<"Base\n";}
};

class Derrived : public Base {
    public:
        void print() { std::cout<<"Derived\n";}
};

void sumFun(Base& b) {
    b.print();
}


int main() {
    // Base b;
    Derrived d;
    sumFun(d);
}
