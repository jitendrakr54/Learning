//  What is the differnce between pointer and reference
// 1. Memory Address
// 2. Reassignement is not possible
// 3. Null value
// 4. Arithmetic operations not supported with references
// 5. Indirection

#include <iostream>

int main() {
    int i = 10;

    //1st
    // int &r = i;
    // int *p = &i;
    // std::cout<<"Addresses: "<<&i<<"\t"<<&r<<"\t"<<p<<"\n";

    //2nd
    // int &r = i;
    // int *p = &i;
    // int var = 50; 

    // r = var;     // r doesn't point to var rather it keeps pointing to i and change value of i to value of var 50
    // p = &var;  
    // std::cout<<r<<"\t"<<i<<"\t"<<*p<<"\n";

    // 3rd diff
    // int *p = nullptr;
    // int &r;             // not possible
    // r = i;              // not possible
    // p = &i;             // possible

    // 4th diff
    int *p = &i;
    int **ptr = &p;
    int ***pptr = &ptr;     // multilevel indirection is possible with pointer
    int &r = i;             // only one level of indirection is possible with reference
    return 0;
}