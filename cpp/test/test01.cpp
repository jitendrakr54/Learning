#include <iostream>

int* retArray() {
    int *arr = new int[5];
    for(int i=0; i<5; i++) {
        arr[i] = i;
    }
    return arr;
}

int main() {
    int* arr = retArray(); 
    std::cout<<arr[0]<<arr[1];
    return 0;
}