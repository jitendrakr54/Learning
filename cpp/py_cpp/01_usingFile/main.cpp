#include <iostream>
#include <fstream>

int main() {
    std::ofstream out{"sample.txt"};
    std::string str;
    std::cout<<"Enter something: ";
    std::cin>>str;
    out<<str;
    out.close();
    return 0;
}