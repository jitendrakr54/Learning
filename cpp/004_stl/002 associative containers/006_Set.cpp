// 1. std::set is an Associative Container that contains a sorted set of unique objects of type Key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in set then we will have to provide 
//    compare function so that set can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// It store unique elements and they are stored in sorted order (A/D)

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
#include <map>
#include <vector>

class Person {
    public:
        int m_age;
        std::string m_name;
        Person(int age, std::string name) : m_age{age}, m_name{name} {}
        Person(const Person&) { std::cout<<"Copy\n"; }
    bool operator < (const Person& rhs) const { return m_age < rhs.m_age; }
    bool operator > (const Person& rhs) const { return m_age > rhs.m_age; }
};

// int main() {
//     std::set<Person, std::greater<>> st{{27, "Jitendra"}, {25, "Khush"}, {26, "Prince"}};
//     // st.insert(28, "Sonu"); // compilation error
//     st.insert({29, "Chomu"});
//     st.emplace(28, "Sonu");
//     auto print = [](const Person &p){ std::cout<<p.m_age<<" "<<p.m_name<<"\n"; };
//     std::for_each(st.begin(), st.end(), print);
//     st.erase(st.begin());
//     std::for_each(st.begin(), st.end(), print);
//     return 0;
// }

// int main() {
//     std::set<int> st{3, 5, 1, 2, 6};
//     st.erase(9);
//     std::cout<<*(st.end());
//     if(st.find(6) != st.end()) {
//         std::cout<<"yes\n";
//     } else {
//         std::cout<<"no\n";
//     }
//     return 0;
// }

// int main() {
//     std::vector<int> v{1,2,3}; 
//     std::sort(v.begin(), v.end());

//     // for(int i=1; i<=s.size(); i++) {
//     //     int found = 0;
//     //     for(int j=0; j<=s.size(); j++) {
//     //         if(v[j] == i) {
//     //             found = 1;
//     //         }
//     //     }
//     //     if(found == 0) {
//     //         std::cout<<i<<"\n";
//     //     }
//     // }
//     // std::cout<<*(s.rbegin());

//     for(int i=0; i<v.size()-1; i++) {
//         if((v[i+1] - v[i]) > 1) {
//             std::cout<<v[i]+1;
//         }
//     }
//     std::cout<<v[v.size()-1]+1;
// }