#include <iostream>

struct Person {
    // static int a = 5;
    int b{3};
    Person() {}
    ~Person() { std::cout<<"Person des\n"; }
    virtual void print() = 0;
};

struct Student : public Person {
    Student() {}
    ~Student() { std::cout<<"Student des\n"; }
    void print() {
        std::cout<<"Student\n";
    }
};

int main() {
    Person p;
    // p = new Student;
    // p->print();
    // delete p;
}