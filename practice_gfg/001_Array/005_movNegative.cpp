// Move all the negative elements to one side of the array 

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	// 1st method
    // int arr[] = {5, 2, -3, 4, 5, 6, -7, 8, 9};
    // int size = sizeof(arr)/sizeof(arr[0]);
    
    // int j=0;
    // for(int i=0; i<size; i++) {
    //     if(arr[i]<0){
    //         if(i != j){
    //             std::swap(arr[i], arr[j]);
    //         }
    //         j++;
    //     }
    // }
    
    // for(int i=0; i<size; i++) {
    //     std::cout<<arr[i]<<" ";
    // }

    // 2nd Method
    std::vector<int> v{-1, 2, -3, 4, 5, 6, -7, 8, 9};
    std::partition(v.begin(), v.end(), [](int x){ return x<0; });
    for(auto i: v) {
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
	return 0;
}