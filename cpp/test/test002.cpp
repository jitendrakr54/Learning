#include <iostream>


class A {
    private:
        std::string m_str;
    public:
        
        A(std::string str) : m_str(str) {}
        // int change(std::string str) { std::cout<<"Function 1\n";  m_str = "hello"; return 2;}
        const int change(std::string str) { std::cout<<"Function 1\n";  m_str = "hello"; return 2;} 
        // const int change(std::string str) const { 
        //     // m_str = "hello";       // not allowed, const fucntion can't change m_str
        //     std::cout<<"Function 2 \n"; 
        //     str = "hello";      // but str can be changes as it is not const
        //     return 2;
        // } 
        // const int change(const std::string str) const { std::cout<<"Function 1\n"; str = "hello"; return 2;}   

        static void fun() {
            // std::cout<<m_str;
        }   
};

int main() {
    const A a("hi");
    // a.change("hello");  // const func is required for this
    A b("hi");
    b.change("hello");
    return 0;
}