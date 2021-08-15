// 0. std::stack class is a container adapter that gives the programmer the functionality of a stack.
// 1. Internally it uses std::deque STL container.
// 2. It is LIFO (last-in, first-out) data structure.
// 4. std::stack allows to push(insert) and pop(remove) only from back.
// 5. The class template acts as a wrapper to the underlying container - only a specific set of functions is provided.
// 6. The stack pushes and pops the element from the back of the underlying container, known as the top of the stack.

// ELEMENT ACCESS:
//     top()

// CAPACITY:
//     empty(), size()

// MODIFIERS:
//     push(), emplace(), pop(), swap()

// Time complexity for push(), pop() operation is O(1), as these all operation are done from top of the stack

#include <algorithm>
#include <iostream>
#include <stack>

void print(std::stack<int>s) {
    while(!s.empty()) {
        std::cout<<s.top()<<"\n";
        s.pop();
    }
}

int main() {
    // std::stack<int> s;
    std::stack<int, std::deque<int>> s;
    s.push(2);
    s.push(3);
    s.push(4);
    print(s);
    return 0;
}