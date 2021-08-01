// 0. std::queue class is a container adapter that gives the programmer the functionality of a queue
// 1. queue is FIFO (first-in, first-out) data structure.
// 2. The class template acts as a wrapper to the underlying container - only a specific set of functions is provided.
// 3. The queue pushes the elements on the back of the underlying container and pops them from the front.

// ELEMENT ACCESS:
//     front(), back()

// CAPACITY:
//     empty(), size()

// MODIFIERS:
//     push(), emplace(), pop(), swap()


#include <algorithm>
#include <iostream>
#include <queue>

void print(std::queue<int>q) {
    while(!q.empty()) {
        std::cout<<q.front()<<"\n";
        q.pop();
    }
}

int main() {
    std::queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    print(q);
    return 0;
}