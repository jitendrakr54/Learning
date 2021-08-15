#include <algorithm>
#include <iostream>
#include <map>
#include <set>

int doUnion(int a[], int n, int b[], int m)  {
    //code here
    std::set<int> st;
    for(int i=0; i<n; ++i) {
        st.insert(a[i]);
    }
    for(int i=0; i<m; ++i) {
        st.insert(b[i]);
    }
    // std::set<int>::iterator it;
    // for(auto itr = st.begin(); itr!=st.end(); ++itr) {
    //     std::cout<<*itr<<" ";
    // }
    // for(auto it : st) {
    //     std::cout<<it<<" ";
    // }

    std::for_each(st.begin(), st.end(), [](int x) { std::cout<<x<<" ";});
    return st.size();
}

int main() {
    int a[] = {1, 1, 2, 2, 3, 3};
    int b[] = {8, 9, 7, 6, 5};
    doUnion(a, 6, b, 5);
    return 0;
}

