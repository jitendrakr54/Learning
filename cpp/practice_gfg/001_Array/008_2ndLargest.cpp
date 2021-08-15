#include <iostream>
#include <vector>

int secondLargest(std::vector<int> v) {
    int first = 0, second = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i] > first) {
            first = v[i];
        }
    }

    for(int i=0; i<v.size(); i++) {
        if(v[i] > second && v[i] != first) {
            second = v[i];
        }
    }
    return second;
}

int main() {
    std::vector<int> v{20, 13, 26, 44, 10, 33};
    std::cout<<secondLargest(v)<<"\n";
    return 0;
}