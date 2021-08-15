#include <iostream>
#include <cstring>

class Demo {
    private:
        int *m_ptr;

};
class MyString {
    private:
        char *m_str;
        int length;
    public:
        MyString() : m_str{nullptr}, length{0} {}
        MyString(const char *str="") {
            length = strlen(str)+1;
            m_str = new char[length];
            for(int i=0; i<length; i++) {
                m_str[i] = str[i];
            }
            m_str[length] = '\0';
        }
        ~MyString() {
            delete[] m_str;
        }
        MyString(const MyString &m) {
            length = m.length;
            m_str = new char[length];
            for(int i=0; i<length; i++) {
                m_str[i] = m.m_str[i];
            }
        }
        MyString& operator = (const MyString &m) {
            length = m.length;
            delete m_str;
            m_str = new char[length];
            for(int i=0; i<length; i++) {
                m_str[i] = m.m_str[i];
            }
            return *this;
        }
        friend std::ostream& operator <<(std::ostream &out, const MyString &m);
        char* getString() const { return m_str; }
};

std::ostream& operator <<(std::ostream &out, const MyString &m) {
    out<<m.getString();
    return out;
}
int main() {
    MyString m = "Hello";
    std::cout<<m;
}