#include <iostream>
#include <algorithm>
#include <stack>

std::string reverseWord(std::string input) {
    std::reverse(input.begin(), input.end());
    input.append(" ");

    int n = input.length();
    int j=0;
    for(int i=0; i<n; i++) {
        if(input[i] == ' ') {
            std::reverse(input.begin()+j, input.begin()+i);
            j = i+1;
        }
    }
    input.pop_back();
    return input;
}

std::string reverseWord1(std::string input) {
    std::stack<std::string> st;
    int j =0;
    input.append(" ");
    for(int i=0; i<input.length(); i++) {
        if(input[i] == ' ') {
            st.push(std::string(input.begin()+j, input.begin()+i));
            j = i+1;
        }
    }

    std::string output;
    int size = st.size();
    for(int i=0; i<size; i++) {
        output.append(st.top());
        output.append(" ");
        st.pop();
    }
    return output;
}

int main() {
    std::string input = "I LIKE TO RUN";
    std::cout<<reverseWord(input)<<"\n";
    std::cout<<reverseWord1(input)<<"\n";
    return 0;
}