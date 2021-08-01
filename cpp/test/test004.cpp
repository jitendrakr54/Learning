#include <iostream>

int& sum() {
    int sum = 9;
    return sum;
}

int* sum1() {
    int sum;
    sum = 9;
    return &sum;
}

int main() {
    int &a = sum();
    std::cout<<a;
}