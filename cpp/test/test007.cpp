#include <iostream>

class Demo {
    int d;
    public:
        Demo() : d{0} {}
        Demo(Demo& tmp) {
            d = tmp.d;
        }
        friend void show(Demo &d);
};

void show(Demo &d) {
    std::cout<<d.d;
}
class A {
    int a[10];
};

class B : public A {};
class C : public A {};

class D : public B, public C {};

class AAA {
    public:
        ~AAA() noexcept { throw 22; }
};
int main() {
    // std::cout<<sizeof(D);

    try {
        AAA a;
        throw 20;
    } catch(int a) {
        std::cout<<a<<"\n";
    }
    return 0;
}