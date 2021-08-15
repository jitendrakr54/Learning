// dynamic_cast in C++
// SYSNTAX: dynamic_cast<new_type> (expression)

// Need for dynamic_cast:
// When dealing with polymorphism, you’ll often encounter cases where you have a pointer to a base class, 
// but you want to access some information that exists only in a derived class.

// NOTES:
// 0. dynamic_cast is used at run time to find out correct down-cast.
// 1: Need at least one virtual function in base class, otherwise fails with compiler error.
// 2: If the cast is successful, dynamic_cast returns a value of type new_type. 
// 3: If the cast fails and new_type is a pointer type, it returns a null pointer of that type.
// 4: If the cast fails and new_type is a reference type, it throws an exception that matches a handler of 
//    type std::bad_cast.

// BOTTOM LINE:
// 1. work only on polymorphic base class (at least one virtual function in base class) because it uses this
//    information to decide about wrong down-cast (to decide safe downcasting).
// 2. it is used for up-cast (D to B) and down-cast (B to D), but it is mainly used for correct downcast.
// 3. using this cast has run time overhead, because it checks object types at run time using RTTI 
//    (Run Time Type Information).
// 4. if we are sure that we will never cast to wrong object then we should always avoid this cast and use 
//    static_cast.

#include <iostream>

class Base {
    public:
        virtual void print() { std::cout<<"Base\n"; }
};

class Derived1 : public Base{
    public:
        void print() { std::cout<<"Derived1\n"; }
        void printDerived1() { std::cout<<"printDerived1\n"; }
};

class Derived2 : public Base{
    public:
        void print() { std::cout<<"Derived2\n"; }
        void printDerived2() { std::cout<<"printDerived2\n"; }
};

int main() {
    // Derived1 d1;
    // Base* bp = &d1;
    // Derived2 d2;
    // Base* bp = &d2;
    // Derived1* dp1 = dynamic_cast<Derived1*>(bp);
    // if(dp1 == nullptr) {
    //     std::cout<<"NULL\n";
    // } else {
    //     std::cout<<"Not NULL\n";
    //     dp1->print();
    // }

    // Derived1 d1;
    // Base &b1 = d1;
    // // Derived2 d2;
    // // Base &b1 = d2;
    // try {
    //     Derived1 &r1 = dynamic_cast<Derived1&>(b1);
    //     r1.print();
    //     r1.printDerived1();
    // } catch(std::exception &e) {
    //     std::cout<<e.what()<<"\n";
    // }

    // Downcasting using static_cast
    // Derived1 d1;
    // Base &b1 = d1;
    // Derived2 d2;
    // Base &b1 = d2;
    // Derived1 &r1 = static_cast<Derived1&>(b1);
    // r1.print();
    // r1.printDerived1();
    return 0;
}