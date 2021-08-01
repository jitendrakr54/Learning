// 1. std::vector is a sequence container and also known as Dynamic Array or Array List.
// 2. Its size can grow and shrink dynamically, and no need to provide size at compile time.
// 3. The elements are stored contiguously, which means that elements can be accessed not only through iterators, but
//    also using offsets to regular pointers to elements. This means that a pointer to an element of a vector may be
//    passed to any function that expects a pointer to an element of an array.
// 4. The storage of the vector is handled automatically, being expanded and contracted as needed.
// 5. Vectors usually occupy more space than static arrays, because more memory is allocated to handle future growth. 
//    This way a vector does not need to reallocate each time an element is inserted, but only when the additional 
//    memory is exhausted. 
// 6. Extra memory can be returned to the system via a call to shrink_to_fit()
// 7. Reallocations are usually costly operations in terms of performance. The reserve() function can be used to 
//    eliminate reallocations if the number of elements is known beforehand.

// COMPLEXITIES:
//    . Random access - constant 𝓞(1)
//    . Insertion or removal of elements at the end - amortized constant 𝓞(1)
//    . Insertion or removal of elements - linear in the distance to the end of the vector 𝓞(n)

// ELEMENT ACCESS:
//      at(), [], front(), back(), data()

// ITERATORS:
//      begin(), cbegin(), end(), cend(), rbegin(), crbegin()

// CAPACITY:
//      empty(), size(), max_size(), reserve(), capacity(), shrink_to_fit()

// MODIFIERS:
//      insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

// emplace() : construct element in-place and avoids
// shrink_to_fit(): reduces memory usage by freeing unused memory

#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;
    v[2] = 3;
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(7);
    std::cout<<"Size: "<<v.size()<<" Capacity: "<<v.capacity()<<"\n";
    v.shrink_to_fit();
    std::cout<<"Size: "<<v.size()<<" Capacity: "<<v.capacity()<<"\n";
    return 0;
}