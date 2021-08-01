// 1. std::array is a container that encapsulates fixed size arrays.
// 2. array size is needed at compile time.
// 3. Assign by value is actually by value.
// 4. Unlike a C-style array, it doesn't decay to T* automatically.

// ELEMENT ACCESS:
//    at(), [], front(), back(), data() // gives access to the underlying array

// ITERATORS:
//    begin(), cbegin(), end(), cend(), rbegin(), crbegin(), rend(), crend()

// CAPACITY:
//    empty(), size(), max_size()

// OPERATIONS:
//    fill(), swap()

#include <algorithm>
#include <array>
#include <iostream>

int main() {
    std::array<int, 5> arr{10, 20, 30, 40, 50};
    
    return 0;
}