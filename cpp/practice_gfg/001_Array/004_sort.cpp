// Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
#include <algorithm>
#include <iostream>

void sort1(int a[], int n) {
    int low = 0;
    int mid = 0;
    int high = n-1;
    
    while(mid <= high) {
        switch(a[mid]) {
            case 0:
                std::swap(a[low++], a[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                std::swap(a[mid++], a[high--]);
                break;
        }
    }
}

void sort2(int a[], int n) {
    int cnt0, cnt1, cnt2;
    cnt0 = cnt1 = cnt2 = 0;

    int i;
    for(i=0; i<n; i++) {
        switch(a[i]) {
            case 0:
                cnt0++;
                break;
            case 1:
                cnt1++;
                break;
            case 2:
                cnt2++;
                break;
        }
    }
    // std::cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<"\n";
    i = 0;
    while(cnt0 > 0) {
        a[i++] = 0;
        cnt0--;
    }

    while(cnt1 > 0) {
        a[i++] = 1;
        cnt1--;
    }

    while(cnt2 > 0) {
        a[i++] = 2;
        cnt2--;
    }
}
void print(int arr[], int n) {
    for(int i=0;i<n; i++) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

int main() {
    int arr[5]{0, 2, 1, 2, 0};
    sort2(arr, 5);
    print(arr, 5);
    return 0;
}