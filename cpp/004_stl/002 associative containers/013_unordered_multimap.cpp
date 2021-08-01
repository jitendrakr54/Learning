// 0. Unordered multimap is an unordered associative container that supports equivalent keys (an unordered_multimap 
//    may contain multiple copies of each key value) and that associates values of another type with the keys. 
// 1. Search, insertion, and removal have average constant-time complexity.
// 2. Internally, the elements are not sorted in any particular order, but organized into buckets.
// 3. It uses hashing to insert elements into buckets. 
// 4. This allows fast access to individual elements, since once a hash is computed,
//    it refers to the exact bucket the element is placed into..

// ITERATORS:
//     begin(), cbegin(), end(), cend()

// CAPACITY:
//      empty(), size(), max_size()

// MODIFIERS:
//      insert(), emplace(), emplace_hint(), swap(), erase(), clear(), extract(), merge()

// LOOKUP:
//      count(), find(), contains(), equal_range()

// OBSERVERS:
//      hash_function(), key_eq()

#include <algorithm>
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_multimap<int, char> unm{{1, 'a'}, {2, 'b'}, {1, 'd'}};
    
    for(const auto &ele : unm) {
        std::cout<<ele.first<<" "<<ele.second<<"\n";
    }

    auto search = unm.find(2);
    if(search != unm.end()) {
        std::cout<<search->first<<" Found! \n";
    }
    return 0;
}