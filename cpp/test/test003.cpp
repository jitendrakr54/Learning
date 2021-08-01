#include <iostream>
#include <vector>
#include <sstream>

int toNumeric(std::string s) {
    std::stringstream stream(s);
    int num;
    stream >> num;
    return num;
}

int toNumeric1(std::string s) {
    int num = 0;
    for(int i=0; i<s.length(); i++) {
        num = num * 10 + s[i] - '0';
    }
    return num;
}

int main() {
    // std::atoi();
    std::string s{"1234"};
    std::cout<<toNumeric1(s)<<"\n";
    return 0;
}