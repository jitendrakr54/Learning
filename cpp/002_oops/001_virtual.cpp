//  In early binding compiler see type of object(pointer), not what is the content of object
#include <iostream>

class A {
    public:
        static int var;
        static int fun() { return var;} 
        void f1() { std::cout<<"A::f1\n";}
        virtual void f2() { std::cout<<"A::f2\n";}
        virtual void f3() { std::cout<<"A::f3\n";}
        virtual void f4() { std::cout<<"A::f4\n";}
};

int A::var = 1;

class B : public A{
    public:
        void f1() { std::cout<<"B::f1\n";}
        void f2() { std::cout<<"B::f2\n";}
        void f4(int a) { std::cout<<a<<" B::f4\n";}
};


int main() {
    A *p;
    B b;
    std::cout<<b.var<<B::var<<b.fun()<<"\n";
    p = &b;
    p->f1(); //EB
    p->f2(); //LB
    p->f3(); //LB
    // p->f4(4); //EB Error, here early binding happens and type of p is A, where there is no matching fun found with f4(int)
    return 0;
}