// const_cast in C++

// The expression const_cast<T>(v) can be used to change the const or volatile qualifiers of pointers or references
// Where T must be a pointer, refrence, or pointer-to-member type.

// Use of const_cast
// 1. When the actual referred object/variable is not const.
// 2. When we need to call some 3rd party library where it is taking variable/object as non-const but not 
//    changing that.

// BOTTOM LINE:
// NEVER USE THIS !!!
// 1. Use only you have to.
// 2. Use only when the actual referred object/variable is not const.
// 3. Use when we are dealing whith 3rd party library and some API want data in non-const form but we have
//    it in const. (Actually we can not do anything in that case, but make sure that API is not changing
//    our value)

#include <iostream>

// 1. When the actual referred object/variable is not const.

// int main() {
//     const int a1 = 10;
//     const int *b1 = &a1;

//     int *d1 = const_cast<int*>(b1);
//     *d1 = 15;  // Invalid and Undefined behavior!
//     std::cout<<a1<<" "<<*d1<<"\n";

//     int a2 = 20;
//     const int *b2 =  &a2;
//     int *d2 = const_cast<int*>(b2);
//     *d2 = 30;
//     std::cout<<a2<<" "<<*d2<<"\n";
//     return 0;
// }

// 2. When we need to call some 3rd party library where it is taking variable/object as non-cats but not 
//    changing that.


// void thirdPartyLibrary(int* x) {
//     int k = 10;
//     // *x = 15;
//     std::cout<<k + *(x)<<"\n";
// }

// int main() {
//     const int x = 20;
//     const int *px = &x;
//     thirdPartyLibrary(const_cast<int*>(px));
//     // std::cout<<*px;
//     return 0;
// }

// 3. const_cast can be used to change non-const class members inside a const member function. 
//    Consider the following code snippet. Inside const member function fun(), ‘this’ is treated by the 
//    compiler as ‘const student* const this’, i.e. ‘this’ is a constant pointer to a constant object, 
//    thus compiler doesn’t allow to change the data members through ‘this’ pointer. const_cast changes the
//    type of ‘this’ pointer to ‘student* const this’.

class student {
private:
    // const int roll;   //not allowed
    int roll;
public:
    // constructor
    student(int r):roll(r) {}
  
    // A const function that changes roll with the help of const_cast
    void fun() const
    {
        ( const_cast <student*> (this) )->roll = 5;
    }
    int getRoll()  { return roll; }
};
  
int main(void) {
    student s(3);
    std::cout << "Old roll number: " << s.getRoll() << std::endl;
  
    s.fun();
  
    std::cout << "New roll number: " << s.getRoll() << std::endl;
  
    return 0;
}

// #include <iostream>
// int main() {
//     int a, b, i = 2;
//     a = i++;
//     std::cout<<i<<"\n";
//     b = ++i;
//     std::cout<<a<<" "<<b<<"\n";
//     return 0;
// }