#include <iostream>
class Person{
    public:
    int a;
    Person(int a = 0 ) : a{a} {
        std::cout<<"Constructor!\n";
    }
    // Person(const Person &obj) = delete;
    Person(const Person &obj) {
        a = obj.a;
        std::cout<<"Copy constructor\n";
    }
    Person(Person &&obj) {
        a = obj.a;
        std::cout<<"Move constructor\n";
    }
    Person& operator=(const Person &obj) {
        a = obj.a;
        std::cout<<"Assignment operator\n";
        return *this;
    }
    Person& operator=(Person &&obj) {
        a = obj.a;
        std::cout<<"Move operator\n";
        return *this;
    }
};

void print(Person p) {
    std::cout<<p.a<<"\n";
}

Person ceratePerson() {
    return Person();
}
int main() {
    // Person p1, p3;
    // Person p2 = p1;
    // p3 = p1;

    // Person p1;
    // Person p2{p1};

    // Person p1;
    // print(p1);

    // Person p1;
    // Person p2;
    // p1 = std::move(p2); // Move assignment

    // Person p3;
    // Person p4 = std::move(p3);  // Move constructor

    Person p5 = ceratePerson();
    return 0;
}