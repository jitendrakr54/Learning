// 1. Multimap is an associative container that contains a sorted list of key-value pairs, 
//    while permitting multiple entries with the same key.
// 2. It store key value pair in sorted order on the basis of key (assending/decending).
// 3. Data structure used in multimap is not defined by standard, but red-black tree is assumed by most of the people.
// 4. Search, insertion, and removal operations have logarithmic complexity.
// 5. We dont have at() and [] functions to get element like we had in std::map.

// ITERATORS:
//     begin(), cbegin(), end(), cend(), rbegin(), crbegin(), rend(), crend()

// CAPACITY:
//      empty(), size(), max_size()

// MODIFIERS:
//      insert(), emplace(), emplace_hint(), swap(), erase(), clear(), extract(), merge()

// LOOKUP:
//      count(), find(), contains(), equal_range(), lower_bound(), upper_bound()

// OBSERVERS:
//      key_comp(), value_comp()

#include <algorithm>
#include <iostream>
#include <map>

int main() {
    std::multimap<char, int> m;
    m.insert(std::make_pair('a', 1));
    m.insert(std::make_pair('a', 2));
    m.insert(std::make_pair('a', 3));
    m.insert(std::make_pair('b', 4));
    m.insert(std::make_pair('b', 5));
    
    std::cout<<m.count('a')<<"\n\n";

    for(const auto& ele: m) {
        std::cout<<ele.first<<" "<<ele.second<<"\n";
    }
    // std::cout<<m.contains('c')<<"\n";
    std::cout<<"\n";
    auto range = m.equal_range('a');
    for(auto it = range.first; it != range.second; ++it) {
        std::cout<<it->first<<" "<<it->second<<"\n";
    }
    return 0;
}