// Write a Code to check whether one string is a rotation of another
// Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
// (eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
#include <iostream>
#include <string>

bool isRotationofString(std::string s1, std::string s2) {
    std::string temp = s1 + s1;
    if(s1.length() != s2.length()) {
        return false;
    }
    return (temp.find(s2) != std::string::npos);
}
// ABCDABCD
int main() {
    std::string s1 = "ABCD";
    std::string s2 = "ACBD";
    std::string res = isRotationofString(s1, s2) ? " is ":" is not ";
    std::cout<<s2<<res<<"rotation of "<<s1<<"\n";
    return 0;
}
