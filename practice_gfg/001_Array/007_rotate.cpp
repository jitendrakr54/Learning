#include <iostream>
#include <vector>

void rotateClockWise(int arr[], int n);
void rotateAntiClockWise(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr1[] = {1,2,3,4,5};
    printArray(arr1, 5);
    rotateClockWise(arr1, 5);
    printArray(arr1, 5);
    int arr2[] = {1,2,3,4,5};
    rotateAntiClockWise(arr2, 5);
    printArray(arr2, 5);
    return 0;
}

void rotateClockWise(int arr[], int n)
{
    int last = arr[n-1];
    std::vector<int> v;
    v.push_back(last);
    for(int i=0; i<n-1; ++i) {
        v.push_back(arr[i]);
    }
    for(int i=0; i<n; ++i) {
        arr[i] = v[i];
    }
    // arr[0] = last;
}

void rotateAntiClockWise(int arr[], int n)
{
    int temp = arr[0];
    for(int i=0; i<n-1; ++i) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; ++i) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}