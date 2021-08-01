// 1. std::multiset is an Associative Container that contains a sorted set of possibly non-unique objects.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in multiset then we will have to provide 
//    compare function so that multiset can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
//     multiset is similar to set except it can have multiple elements with same value.

// ITERATORS:
//     begin(), cbegin(), end(), cend(), rbegin(), crbegin(), rend(), crend()

// CAPACITY:
//      empty(), size(), max_size()

// MODIFIERS:
//      insert(), emplace(), emplace_hint(), swap(), erase(), clear(), extract(), merge()

// LOOKUP:
//      count(), find(), contains(), equal_range(), lower_bound(), upper_bound()

#include <algorithm>
#include <iostream>
#include <set>

class Person {
    public:
        int m_age;
        std::string m_name;
        Person(int age, std::string name) : m_age{age}, m_name{name} {}
    bool operator < (const Person& rhs) const { return m_age < rhs.m_age; }
    bool operator > (const Person& rhs) const { return m_age > rhs.m_age; }
};

int main() {
    std::multiset<Person, std::greater<>> st{{27, "Jitendra"}, {25, "Khush"}, {26, "Prince"}};
    // st.insert(28, "Sonu"); // compilation error
    st.insert({29, "Chomu"});
    st.emplace(28, "Sonu");
    st.insert({29, "Chomu"});
    
    auto print = [](const Person &p){ std::cout<<p.m_age<<" "<<p.m_name<<"\n"; };
    std::for_each(st.begin(), st.end(), print);
    // st.erase(st.begin());
    // std::for_each(st.begin(), st.end(), print);
    return 0;
}

// int main() {
//     std::multiset<int> ms{2, 4, 2, 6, 1, 2, 4};
//     std::cout<<ms.count(2);
// }