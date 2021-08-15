// find duplicate in an array of N+1 Integers
#include <algorithm>
#include <iostream>
#include <vector>

int findDuplicate(std::vector<int>& nums) {
    int d;
    for(auto ele : nums) {
        if(std::count(nums.begin(), nums.end(), ele) >1) {
            d = ele;
        }
    }
    return d;
}

int main() {
    std::vector<int> v{4, 3, 5, 4, 1};
    std::cout<<findDuplicate(v)<<" is duplicate\n";
    return 0;
}