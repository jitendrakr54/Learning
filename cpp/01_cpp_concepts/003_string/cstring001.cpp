#include <iostream>
#include <cstring>

// int main() {
//  Point 1:
//  you can initialize the string upon creation, but you can not assign values to it using the assignment operator after that!
    // char myString[]{"string"};
    // myString = "hello";         // not allowed

    // char myString1[9] = "string"; 
    // myString1 = "hello";         // not allowed


//   Point 2: Since C-style strings are arrays, you can use the [] operator to change individual characters in the string
    // char myString2[]{ "string" };
    // myString2[1] = 'p';
    // std::cout << myString2 << '\n';

//   Point 3:  const char *myString3 = "string"; is equivalent to (const static char myString3[] = "string"; char* str = myString3)
    // char *myString3 = "string"; // warning!!  because "literal string" is considered as constant
    // myString3[0] = 'p';         // Segmentation fault, myString3 might be stored in read only memory. So If you want to modify using
                                // these type of initialization. Store string in stack(See point 2) or in heap

    // char *myString3 = (char*)malloc(50*sizeof(char));
    // strcpy(myString3, "hello");
    // std::cout<<myString3<<"\n";
    // myString3[0] = 'S';
    // std::cout<<myString3<<"\n";  // Sello

    // const char *myString3 = "string";  // no warning
    // std::cout<<myString3<<"\n";

//     return 0;
// }

// Point 4: Passing a string to function
// void fun(const char *str) {
//     const char *str1 = str;
//     std::cout<<str1<<"\n";
// }

// void fun(char str[]) {
//     const char *str1 = str;
//     std::cout<<str1<<"\n";
// }

// int main() {
//     // const char *str = "hello";
//     // fun(str);
//     // fun("hello");

//     char str[] = "hello";
//     fun(str);
//     return 0;
// }


// Point 5: Returning a string to function
// char* getString() {         // use const char* for warning
//     return "test";          // Literal stored in readonly memory, not in stack or heap
// }
// int main() {
//     char* s = getString();  // use const char* for warning
//     s[0] = 'p';             // segmetation fault
//     std::cout<<s<<"\n";
// }

// one way to return string and will be able to change it later

void getString1(char* str) {
    strcpy(str, "test");
}
int main() {
    char str[50];
    getString1(str);
    str[0] = 'p';
    std::cout<<str<<"\n";
    return 0;
}


// void fun() {
//     std::cout<<"Fun";
// }
// int main()
// {
//   // No null-terminator.
//   char vowels[]{ 'a', 'e', 'i', 'o', 'u' };
 
//   // vowels isn't null-terminated. We need to pass the length manually.
//   // Because vowels is an array, we can use std::size to get its length.
//   std::string_view str{ vowels, std::size(vowels) };
 
//   std::cout << str << '\n'; // This is safe. std::cout knows how to print std::string_views.
 

//   std::string_view str1{"hello"};
//   std::cout<<str<<'\n';

// //   auto var = fun;
// //   var();
//   return 0;
// } 