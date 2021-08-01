#include <iostream>

int main() {
    int *p = new int;
    *p =100;
    delete p;
    *p = 5;
    std::cout<<*p<<"\n";

    // int arr[2];
    // arr[3] = 100;

    // int *q;
    // std::cout<<*q<<"\n";
    return 0;
}