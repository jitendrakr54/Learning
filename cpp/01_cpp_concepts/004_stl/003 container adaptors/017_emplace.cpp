// 1. All the containers supports insert and emplace operation to store data. 
// 2. Emplace is used to construct object in-place and avoids unnecessary copy of objects.
// 3. Insert and Emplace is equal for premetive data types but when we deal with heavy objects
//    we should use emplace if we can for efficiency.

#include <iostream>
#include <set>
#include <vector>

class A {
    public:
        int x;
        A(int x = 0) : x{x} {
            std::cout<<"construct\n";
        }
        A(const A& rhs) {
            x = rhs.x; 
            std::cout<<"Copy\n";
        } 
        // A(const A& rhs) = delete;
};
bool operator < (const A& lhs, const A& rhs) {
    return lhs.x < rhs.x;
}

int main() {
    std::set<A> set;
    // set.insert(10);
    set.emplace(11);

    // std::vector<A> v;
    // // v.reserve(5);
    // // A a(10);
    // // v.insert(v.begin(), 10);
    // v.emplace(v.begin()+1, 10);
    return 0;
}