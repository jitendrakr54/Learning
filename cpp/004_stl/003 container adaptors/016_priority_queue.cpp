// 0. std::priority_queue is a container adaptor that provides constant time lookup of the largest(by default) 
//    OR smallest element.
// 1. By default std::vector is the container used inside.
// 2. Cost of insertion and extraction is logarithmic.
// 3. std::priority_queue is implemented using std::make_heap, std::push_heap, std::pop_heap functions.

// ELEMENT ACCESS:
//     top()

// CAPACITY:
//     empty(), size()

// MODIFIERS:
//     push(), emplace(), pop(), swap()

#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <iostream>

template<typename T>
void print_queue(T q) {
    while(!q.empty()) {
        std::cout<<q.top()<<" ";
        q.pop();
    }
    std::cout<<"\n";
}

int main() {
    {
        std::priority_queue<int> q;
        for(int elm : {1, 8, 3, 5, 2, 9, 6, 7, 4, 0}) {
            q.push(elm);
        }
        print_queue(q);
    }

    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        for(int elm : {1, 8, 3, 5, 2, 9, 6, 7, 4, 0}) {
            q.push(elm);
        }
        print_queue(q);
    }

    {
        auto cmp = [](int left, int right) { return (left) < (right); };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> q(cmp);
        for(int elm : {1, 8, 3, 5, 2, 9, 6, 7, 4, 0}) {
            q.push(elm);
        }
        print_queue(q);
    }
}