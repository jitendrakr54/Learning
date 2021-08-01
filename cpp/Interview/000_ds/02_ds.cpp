#include <iostream>
#include <set>

int isduo(int number) {
    std::set<int> st;
    int mod = 0;
    while(number != 0) {
        mod = number%10;
        number = number /10;
        std::cout<<number<<"\n";
        st.insert(mod);
        // if(st.size() > 2) {
        //     break;
        // }
    }
    std::cout<<st.size()<<"\n";
    if(st.size() == 1 || st.size() == 2) {
        return 2;
    }
    return 0;
}

int main() {
    std::cout<<isduo(2020)<<"\n";
}