#include <iostream>

class Base {
    public:
        virtual void fun1() = 0;
        virtual void fun2() = 0;
};
void Base::fun1() {
    std::cout<<"Base fun1\n";
}

class Derived : public Base {
    public:
        void fun1() {
            std::cout<<"Derrived\n";
            Base::fun1();
        }
        void fun2() {
            std::cout<<"Derrived\n";
        }
};
class A {
    public:
        virtual void fun() {}
};

class B : public A{
    public:
        void fun() {}
};

int main() {
    Derived d;
    Base *b = &d;
    b->fun1();
    std::cout<<sizeof(Derived)<<" "<<sizeof(B)<<"\n";
    return 0;
}