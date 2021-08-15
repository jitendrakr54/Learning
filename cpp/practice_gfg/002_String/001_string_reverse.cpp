#include <algorithm>
#include <iostream>
#include <stack>

void reverse(std::string& str) {
    int start = 0;
    int end = str.length()-1;

    while(start < end) {
        std::swap(str[start++], str[end--]);
    }
}

void reverseUsingStack(std::string &str) {
    std::stack<char> st;
    for(char c : str) {
        st.push(c);
    }
    int length = str.length();
    str.clear();
    for(int i=0; i<length; i++) {
        // str[i] = st.top();
        str.push_back(st.top());
        st.pop();
    }
}

int main() {
    std::string str{"hello"};

    // Using inbuilt library
    // std::reverse(str.begin(), str.end());
    // std::cout<<str<<"\n";

    // reverseUsingStack(str);
    // std::cout<<"rev: "<<str<<"\n";

    reverse(str);
    std::cout<<"rev: "<<str<<"\n";
    return 0;
}