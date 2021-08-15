// Find the "Kth" max and min element of an array 
#include <algorithm>
#include <iostream>

int kthSmallest(int arr[], int l, int r, int k) {
    int smallestIndex =0;
    for(int startIndex=0; startIndex<r-1; startIndex++) {
        smallestIndex = startIndex;
        for(int currIndex=smallestIndex+1; currIndex<r; currIndex++) {
            if(arr[currIndex] < arr[smallestIndex]) {
                smallestIndex = currIndex;
            }
        }
        std::swap(arr[startIndex], arr[smallestIndex]);
    }
    // std::sort(arr, arr+r);
    return arr[k-1];
}

int main() {
    int arr[6]{7, 10, 4, 3, 20, 15};
    int smallestOne = kthSmallest(arr, 0, 6, 3);
    std::cout<<smallestOne<<"\n";
    return 0;
}