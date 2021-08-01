// 0. std::unordered_multiset is an associative container that contains set of possibly non-unique objects.
// 1. Search, insertion, and removal have average constant-time complexity.
// 2. Internally, the elements are not sorted in any particular order,, the elements are organized into buckets.
// 3. It uses hashing to insert elements into buckets. 
// 4. Which bucket an element is placed into depends entirely on the hash of its value.
// 5. This allows fast access to individual elements, because after computing the hash of the value it refers to 
//    the exact bucket the element is placed into.

// WHY UNORDERED_MULTISET
// 0. maintain a collection of non-uniqe items with fast insertion and removal.

// ITERATORS:
//     begin(), cbegin(), end(), cend()

// CAPACITY:
//      empty(), size(), max_size()

// MODIFIERS:
//      insert(), emplace(), emplace_hint(), swap(), erase(), clear(), extract(), merge()

// LOOKUP:
//      count(), find(), contains(), equal_range()

#include <algorithm>
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> unst{4, 1, 2, 3, 4, 2, 3, 5, 10, 11};
    auto search = unst.find(2);
    if(search != unst.end()) {
        std::cout<<(*search)<<" Found!\n";
    } else {
        std::cout<<"Not found!\n";
    }

    for(auto &e: unst) {
        std::cout<<e<<" ";
    }
    return 0;
}