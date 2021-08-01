#include <iostream>
#include <list>

class A {
    public:
        virtual int value() { return 1;}
};

class B : public A {
    public:
        int value() { return 2;}
};
int main() {
    // A *obj = new B();
    // int val = obj->value();

    // std::list<int> coll;
    // std::list<int>::iterator it = coll.begin();
    // std::cout<<val<<"\n";

    int i = 1;
    int i1 = 10;
    std::cout<<(i/i1)<<"\n";
}