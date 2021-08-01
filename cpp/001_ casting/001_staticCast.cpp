// static_cast
// 1. It can be used to convert a value of one type to a value of another type.
// 2. The main advantage of static_cast is that it provides compile-time type checking, making it harder to 
//    make an inadvertent error.
// 3. Use static_cast when conversion between types is provided through conversion operator or 
//    conversion constrcutor.
// 4. static_cast is more restrictive than C-style.
//    Eg: char* to int* is allowed in c-style but not with static_cast
// 5. static_cast avoid cast from derived to private base pointer.
// 6. Use for all upcasts, but never use for confused down cast.
// 7. static_cast should be preferred when convertng to void* OR from void*


// BOTTOM LINE:
// 1. For compatible type conversion, such as float to int.
// 2. For conversion operator and conversion constructors.
// 3. To avoid unrealted pointer conversion.
// 4. Avoids derived to private base pointer conversion.
// 5. Use for all up-cast but never use for confused down-cast because there are no runtime checks performed
//    for static_cats conversion.
// 6. Intensions are more clear in C++ style cast (express your better and make code review easier)
// 7. Finding is easy
// 8. Error found at compile-time.

#include <iostream>

// int main() {
//     // char c{'a'};
//     // std::cout<<c<<' '<<static_cast<int>(c)<<"\n"; // prints a 97

//     int i1 { 10 };
//     int i2 { 4 };
 
//     // convert an int to a float so we get floating point division rather than integer division
//     float f { static_cast<float>(i1) / i2 }; 
//     std::cout<<f<<"\n";
//     return 0;
// }

// 3. Use static_cast when conversion between types is provided through conversion operator or 
//    conversion constrcutor.

// class Int {
//     int x;
//     public:
//         Int(int x = 0) : x{x} { std::cout<<"Conversion constructor"<<std::endl;}
//         operator std::string() {
//             std::cout<<"Conversion operator"<<std::endl;
//             return std::to_string(x);
//         }
// };

// int main() {
//     Int obj = 20;
//     std::string str1 = obj;

//     std::string str2 = static_cast<std::string>(obj);
//     obj = static_cast<Int>(30);
//     return 0;
// }

// 4. static_cast is more restritive than C-style.
//    Eg: char* to int* is allowed in c-style but not with static_cast

// int main() {
//     char c;             // 1 byet data
//     int *p = (int*)&c;  // 4 bytes data
//     *p = 5;             // PAss at compile time but FAIL at run time. (that's why it is dangerous)
//     std::cout<<*p<<"\n"; // Segmentation fault (core dumped)
//     // int *p = static_cast<int*>(&c); // FAIL, compile time error, beacause not compatible pointer tyeps.
//     return 0;
// }


// 5. static_cast avoid cast from derived to private base pointer.

// Progarm 4
// class Base{};
// class Derived : private Base {};
// int main() {
//     Derived d1;
//     Base *bp1 = (Base*)&d1;         // Allowed at compile-time
//     // Base *bp2 = static_cast<Base*>(&d1); // Not allowed at compile-time
// }

// 6. Use for all upcasts, but never use for confused down cast.

// class Base {};
// class Derived1: public Base{};
// class Derived2: public Base{};

// int main() {
//     Derived1 d1;
//     Derived2 d2;

//     Base *bp1 = static_cast<Base*>(&d1);
//     Base *bp2 = static_cast<Base*>(&d2);

//     Derived1 *d1p = static_cast<Derived1*>(bp2);
//     Derived1 *d2p = static_cast<Derived1*>(bp1);
//     return 0;
// }

// 7. static_cast should be preferred when convertng to void* OR from void*

int main() {
    int i = 10;
    void *v = static_cast<void*>(&i);
    int *ip = static_cast<int*>(v);
    return 0;
}


