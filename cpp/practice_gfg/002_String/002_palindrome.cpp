#include <algorithm>
#include <iostream>
#include <string>

bool isPalindrome(std::string str) {
    std::string ori{str};
    std::reverse(str.begin(), str.end());
    if(ori == str) {
        return true;
    } else {
        return false;
    }
}
int main() {
    std::string str{"abba"};
    if(isPalindrome(str)) {
        std::cout<<str<<" is palindrome\n";
    } else {
         std::cout<<str<<" is not palindrome\n";
    }
    return 0;
}