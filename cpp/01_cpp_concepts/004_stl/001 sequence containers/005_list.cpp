// 1. This is double linked list what we know from C prgramming language.
// 2. List is sequence container that allow non-contiguous memory allocation.
// 3. List is faster compared to other sequence containers (vector, forward_list, deque) in terms of 
//    insertion, removal and moving elements in any position provided we have the iterator of the position. 
// 4. We should use this class instead of traditional double linked list because
//    a. Well tested
//    b. Bunch of available function
// 5. It supports constant time insertion and removal of elements from anywhere in the container.
// 6. Fast random access is not supported.
// 7. Compared to std::forward_list this provides bidirectional iteration capability while being less space efficient.

// ELEMENT ACCESS:
//     front(), back()

// ITERATORS:
//     begin(), cbegin(), end(), cend(), rbegin(), crbegin(), rend(), crend()

// CAPACITY:
//      empty(), max_size(), size()

// MODIFIERS:
//      insert, emplace, push_back(), emplace_back(), pop_back(), push_front(), emplace_front(), pop_front(), resize(),
//      swap(), erase, clear()

// OPERATIONS:
//      merge(), splice(), remove(), remove_if(), reverse(), unique(), sort()

// splice() : moves elements from another list
// unique() : removes consecutive duplicate elements

#include <algorithm>
#include <list>
#include <iostream>

int main() {
    std::list<int> list1{1, 2, 2, 4, 5, 2};
    std::list<int> list2{6, 7, 8, 9};

    // list1.splice(list1.begin(), list2);
    // list1.unique();
    for(const auto &ele : list1) {
        std::cout<<ele<<" ";
    }
    std::cout<<"\n";
    for(const auto &ele : list2) {
        std::cout<<ele<<" ";
    }
    return 0;
}