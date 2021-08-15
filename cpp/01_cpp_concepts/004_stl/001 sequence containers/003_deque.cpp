// 0. std::deque is an indexed sequence container.
// 1. It allows fast insertion at both beginning and end.
// 2. Unlike vector elements of deque are not stored contiguous.
// 3. It uses individual allocated fixed size array, with additional bookkeeping, meaning index based access to deque
//    must perform two pointer dereference, but in vector we get in one dereference.
// 4. The storage of a deque is automatically expanded and contracted as needed.
// 5. Expansion of deque is cheaper than expansion of vector because it does not copy data.
// 6. A deque holding just one element has to allocate its full internal array (e.g. 8 times the object size on 
//    64-bit libstdc++; 16 times the object size or 4096 bytes, whichever is larger, on 64-bit libc++).

// TIME COMPLEXITY:
//    . Random access - constant O(1)
//    . Insertion or removal of elements at the end or beginning - constant O(1)
//    . Insertion or removal of elements - linear O(n)

// ELEMENT ACCESS:
//     at(), [], front(), back()

// ITERATORS:
//     begin(), cbegin(), end(), cend(), rbegin(), crbegin()

// CAPACITY:
//      empty(), size(), max_size(), reserve(), shrink_to_fit()

// MODIFIERS:
//      insert(), emplace(), push_back(), emplace_back(), pop_back(), push_front(), emplace_front(), pop_front(), 
//      resize(), swap(), erase(), clear()


#include <algorithm>
#include <deque>
#include <iostream>

int main() {
    std::deque<int> dq{10, 20, 30, 40, 50, 60};
    
    return 0;
}