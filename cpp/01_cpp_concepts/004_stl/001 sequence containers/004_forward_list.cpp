// 1. This is single linked list what we know from C programming language.
// 2. Why forward_list why not single_list ?
// 3. We should use this class instead of traditional single linked list because
//    a. Well tested
//    b. Bunch of available function
// 4. It supports fast insertion and removal of elements from anywhere in the container.
// 5. Fast random access is not supported.
// 6. It is implemented as a singly-linked list.
// 7. Compared to std::list this container provides more space efficient storage when bidirectional iteration is not
//    needed.

// ELEMENT ACCESS:
//     front()

// ITERATORS:
//     begin(), cbegin(), end(), cend(), before_begin(), cbefore_begin()

// CAPACITY:
//      empty(), max_size()

// MODIFIERS:
//      insert_after(), emplace_after(), push_front(), emplace_front(), pop_front(), resize(), swap(), 
//      erase_after(), clear()

// OPERATIONS:
//      merge(), splice_after(), remove(), remove_if(), reverse(), unique(), sort()

#include <algorithm>
#include <forward_list>
#include <iostream>

int main() {
    // Initializing forward list
    std::forward_list<int> flist1 = {10, 20, 30};
     
    // Initializing second list
    std::forward_list<int> flist2 = {40, 50, 60};
     
    // Shifting elements from first to second
    // forward list after 1st position
    flist2.splice_after(flist2.begin(), flist1);
     
    // Displaying the forward list
    std::cout << "The forward list after splice_after operation : ";
    for (int&c : flist2)
       std::cout << c << " ";
    std::cout << std::endl;
    return 0;
}