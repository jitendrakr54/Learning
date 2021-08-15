// 0. Unorder Set is a associative container that contains set of unique objects.
// 1. Search, insertion, and removal have average constant-time complexity.
// 2. Internally, the elements are not sorted in any particular order, the elements are organized into buckets.
// 3. It uses hashing to insert elements into buckets.
// 4. Which bucket an element is placed into depends entirely on the hash of its value.
// 5. This allows fast access to individual elements, since once a hash is computed, 
//    it refers to the exact bucket the element is placed into.

// WHY UNORDERED SET?
// 0. maintain a collection of unique items with fast insertion and removal.

// ITERATORS:
//     begin(), cbegin(), end(), cend()

// CAPACITY:
//      empty(), size(), max_size()

// MODIFIERS:
//      insert(), emplace(), emplace_hint(), swap(), erase(), clear(), extract(), merge()

// LOOKUP:
//      count(), find(), contains(), equal_range()

// BUCKET INTERFACE
//      begin(size_type), cbegin(size_type), end(size_type), cend(size_type), bucket_count(), max_bucket_count(),
//      bucket_size(), bucket()

#include <algorithm>
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> unst{4, 1, 3, 2, 4, 2, 3, 5};
    auto search = unst.find(2);
    if(search != unst.end()) {
        std::cout<<(*search)<<" Found!\n";
    } else {
        std::cout<<"Not found!\n";
    }
    std::cout<<unst.bucket_count()<<" "<<unst.bucket_size(2)<<"\n";
    for(auto &e: unst) {
        std::cout<<e<<" ";
    }

    return 0;
}