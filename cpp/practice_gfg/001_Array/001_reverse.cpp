// Reverse the array
#include <algorithm>
#include <iterator>
#include <iostream>
#include <stack>

void reverseArray(int arr[], int start, int end) {
    while(start < end) {
        std::swap(arr[start], arr[end]);
        ++start;
        --end;
    }
}

void reverseString(std::string& s) {
    int start = 0;
    int end = s.length()-1;
    while(start < end) {
        std::swap(s[start], s[end]);
        ++start;
        --end;
    }
}

void reverseStringUsingStack(std::string& s) {
    std::stack<char> st;
    for(char c : s) {
        st.push(c);
    }

    int length = s.length();
    s.clear();
    for(int i = 0; i <length; ++i) {
        s.push_back(st.top());
        st.pop();
    }
    std::cout<<"s: "<<s<<"\n";
}

void printArray(int arr[], int size) {
    for(int i=0; i<size; ++i) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);
    reverseArray(arr, 0, size-1);
    printArray(arr, size);

    std::string str{"Geeks"};
    // reverseString(str);
    std::cout<<str<<"\n";
    reverseStringUsingStack(str);
    std::cout<<str<<"\n";
    return 0;
}