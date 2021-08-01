//  There are the two classes that you will actually use. 
//  std::string is used for standard ascii and utf-8 strings. 
//  std::wstring is used for wide-character/unicode (utf-16) strings. 
//  There is no built-in class for utf-32 strings (though you should be able to extend your own from 
//  basic_string<> if you need one).

//  MEMBER FUNCTIONS:
//  (constructor), (destructor), operator=, assign(), get_allocator()

//  ELEMENT ACCESS:
//  at(), operator[], front(), back(), data(), c_str()

//  ITERARTORS:
//  begin(), cbegin(), end(), cend(), rbegin(), crbegin(), rend(), crend()

//  CAPACITY:
//  empty(), size(), length(), max_size(), reserve(), capacity(), shrink_to_fit()

//  OPERATIONS:
//  clear(), insert(), erase(), push_back(), pop_back(), append(), operator+=, compare(), starts_with(),
//  ends_with(), contains(), replace(), substr(), copy(), resize(), swap()

//  SEARCH:
//  find(), rfind(), find_first_of(), find_first_not_of(), find_last_of(), find_last_not_of()

//  CONSTANTS:
//  npos

#include <iostream>
#include <string>
 
int main()
{
    using namespace std::literals;
 
    // Creating a string from const char*
    std::string str1 = "hello";
 
    // Creating a string using string literal
    auto str2 = "world"s;
 
    // Concatenating strings
    std::string str3 = str1 + " " + str2;
 
    // Print out the result
    std::cout << str3 << '\n';
 
    std::string::size_type pos = str3.find(" ");
    str1 = str3.substr(pos + 1); // the part after the space
    str2 = str3.substr(0, pos);  // the part till the space
 
    std::cout << str1 << ' ' << str2 << '\n';
 
    // Accessing an element using subscript operator[]
    std::cout << str1[0] << '\n';
    str1[0] = 'W';
    std::cout << str1 << '\n';
}
  

  
