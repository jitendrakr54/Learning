// 0. std::unordered_map is an associative container that contains key-value pairs with unique keys.
// 1. Search, insertion, and removal have average constant-time complexity.
// 2. Internally, the elements are not sorted in any particular order, the elements are organized into buckets.
// 3. It uses hashing to insert elements into buckets.
// 4. This allows fast access to individual elements, because after computing the hash of the value it refers to 
//    the exact bucket the element is placed into.

// WHY UNORDERED_MAP
// 0. maintain a collection of uniqe {key:value} pairs with fast insertion and removal.

// ITERATORS:
//     begin(), cbegin(), end(), cend()

// CAPACITY:
//      empty(), size(), max_size()

// MODIFIERS:
//      insert(), insert_or_assign(), emplace(), emplace_hint(), try_emplace(), swap(), erase(), clear(), 
//      extract(), merge()

// LOOKUP:
//      at(), operator[], count(), find(), contains(), equal_range()

// OBSERVERS:
//      key_comp(), value_comp()

#include <algorithm>
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, char> unm{{1, 'a'}, {2, 'b'}};
    std::cout<<unm[1]<<"\n";
    std::cout<<unm[2]<<"\n";

    unm[1] = 'c';

    for(const auto &ele : unm) {
        std::cout<<ele.first<<" "<<ele.second<<"\n";
    }

    auto search = unm.find(2);
    if(search != unm.end()) {
        std::cout<<search->first<<" Found! \n";
    }
    return 0;
}