// reinterpret_cast

// 1. It can perform dangerous conversions because it can typecast any pointer to any other pointer.
// 2. It is used when you want to work with bits.

// BOTTOM LINE
// The result of a reinerpret_cast cannot safely be used for anything other than being cast back to its 
// original type.
// we should be very careful when using this cast.
// if we use this type of cast then it becomes non-portable product.

#include <iostream>

// class Mango {
//     public:
//         void eatMango() { std::cout<<"Eating mango!\n"; }
// };

// class Banana {
//     public:
//         void eatBanana() { std::cout<<"Eating Banana!\n"; }
// };

// int main() {
//     Mango *m = new Mango();
//     Banana *b = new Banana();
//     Banana *newBanana = reinterpret_cast<Banana*>(m);
//     newBanana->eatBanana();
//     return 0;
// }

// 2. It is used when you want to work with bits.
struct myStruct {
    int x;
    int y;
    char c;
    bool b;
};

int main() {
    myStruct s;
    s.x = 5; s.y = 10; s.c = 'a'; s.b = true;
    int *p = reinterpret_cast<int*>(&s);
    std::cout<<*p<<"\n";
    p++;
    std::cout<<*p<<"\n";
    p++;
    char* c = reinterpret_cast<char*>(p);
    std::cout<<*c<<"\n";
    std::cout<<*(reinterpret_cast<bool*>(++c))<<"\n";
    return 0;
}
