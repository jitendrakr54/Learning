#include <iostream>

class Base {
    private:
        int *m_a;
    public:
        Base() = default;
        Base(int a) {
            m_a = new int;
            *m_a = a;
        }
        Base(const Base &b) {
            std::cout<<"1 Copy Constructor\n";
            m_a= new int;
            *m_a = *(b.m_a);
        }
        Base& operator=(const Base &b) {
            delete m_a;   // need to deallocate because m_a is already created and poning to some location
            m_a = new int;
            *m_a = *(b.m_a);
            return *this;
        }
        ~Base() { delete m_a; }
        void print() {
            std::cout<<*m_a<<"\n";
        }
};

int main() {
    Base b1(5);
    {
        Base b2 = b1;
        b2.print();
    }
    b1.print();

    Base b3(5), b4(10);
    b3 = b4;
    b3.print();
    return 0;
}