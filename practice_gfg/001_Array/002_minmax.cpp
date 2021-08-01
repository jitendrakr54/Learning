// Find the maximum and minimum element in an array
#include <iostream>

struct MinMax
{
    int min;
    int max;
};

MinMax findMinMax(int arr[], int n) {
    MinMax minMax;
    if(n == 1) {
        minMax.min = arr[0];
        minMax.max = arr[0];
    }

    if(arr[0] < arr[1]) {
        minMax.min = arr[0];
        minMax.max = arr[1];
    } else {
        minMax.min = arr[1];
        minMax.max = arr[0];
    }

    for(int i=2; i<n; ++i) {
        if(arr[i] < minMax.min) {
            minMax.min = arr[i];
        } else if(arr[i] > minMax.max) {
            minMax.max = arr[i];
        }
    }
    return minMax;
}

// using selection sort
MinMax findMinMax1(int arr[], int n) {
    int smallestIndex;
    for(int startIndex=0; startIndex<n-1; ++startIndex) {
        smallestIndex = startIndex;
        for(int currentIndex = startIndex+1; currentIndex<n; ++currentIndex) {
            if(arr[currentIndex] < arr[smallestIndex]) {
                smallestIndex = currentIndex;
            }
        }
        std::swap(arr[startIndex], arr[smallestIndex]);
    }
    MinMax minMax;
    minMax.min = arr[0];
    minMax.max = arr[n-1];
    return minMax;
}
// std::sort(std::begin(array), std::end(array));

int main() {
    int arr[] = {3, 2, 1, 0, 19, 5};
    MinMax minMax = findMinMax1(arr, std::size(arr));
    std::cout<<minMax.min<<" "<<minMax.max;
    return 0;
}