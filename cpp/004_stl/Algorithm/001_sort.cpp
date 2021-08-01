// TOPIC: STL Algorithm Sort

// NOTES:
// 0. In C++ STL we have sort function which can be sort in increasing and decreasing order.
// 1. Not only integral but user defined data can be sorted using this function.
// 2. Internally it uses IntroSort which is combination of QuickSort, HeapSort and InsertionSort.
// 3. By default, it uses Quicksor but if QuickSort is doing unfair partitioning and taking more than N*logN time,
//    it switches to HeapSort and when the array size becomes really small, it switches to InsertionSort.
// 4. We can use parallel execution policy for better performance.

// TYPES:
// 1. Sorting integral data types
// 2. Sorting user defined data types
// 3. Sort using a fucntion object
// 4. Sort using lamda expression

#include <algorithm>
#include <iostream>
#include <vector>
#include <execution>

// 1. Sorting integral data types

// int main() {
//     std::vector<int> vec{5, 4, 6, 2, 7, 8, 9, 1};
//     std::sort(vec.begin(), vec.end());
//     for(auto elm : vec) {
//         std::cout<<elm<<" ";
//     }
//     std::cout<<"\n";
//     return 0;
// }

// 2. Sorting user defined data types

// class Point {
//     public:
//         int x;
//         int y;
//         Point(int x=0, int y=0) : x{x}, y{y} {}
//         bool operator <(const Point& p) {
//             return ((x+y) < (p.x+p.y));
//         }
//         bool operator >(const Point& p) {
//             return ((x+y) > (p.x+p.y));
//         }
// };

// int main() {
//     std::vector<Point> vec{{1,2}, {3,1}, {0,1}};
//     std::sort(vec.begin(), vec.end());
//     for(auto elm : vec) {
//         std::cout<<elm.x<<" "<<elm.y<<"\n";
//     }
//     std::cout<<"\n";
//     return 0;
// }

// 3. Sort using a fucntion object

// struct {
//     bool operator()(int a, int b) const{
//         return a < b;
//     }
// } customLess;

// int main() {
//     std::vector<int> vec{5, 4, 6, 2, 7, 8, 9, 1};
//     std::sort(vec.begin(), vec.end(), customLess);
//     for(auto elm : vec) {
//         std::cout<<elm<<" ";
//     }
//     std::cout<<"\n";
// }

// 4. Sort using lamda expression

int main() {
    std::vector<int> vec{5, 4, 6, 2, 7, 8, 9, 1};
    std::sort(vec.begin(), vec.end(), [](int a, int b){ return a > b;});
    for(auto elm : vec) {
        std::cout<<elm<<" ";
    }
    std::cout<<"\n";
    return 0;
}
