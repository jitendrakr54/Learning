#include <iostream>

template <typename T>
void print(T val) {
    std::cout<<val<<"\n";
}

template <>
void print(double d) {
     std::cout<<std::scientific<<d<<"\n";
}

int main() {
    print(5);
    print(3.4);
}