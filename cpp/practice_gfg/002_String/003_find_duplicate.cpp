//  print all the duplicates and their counts in the input string 
#include <algorithm>
#include <iostream>
#include <map>

std::map<char, int> printDups(std::string str) {
    std::map<char, int> mp;
    for(int i=0; i<str.length(); i++) {
        mp[str[i]]++;        // it increment the value at mp[str[i]]
    }

    std::cout<<"\n";
    for(auto it  = mp.begin(); it!=mp.end();) {
        if(it->second == 1) {
            it = mp.erase(it);
        } else {
            ++it;
        }
        // std::cout<<it->first<<it->second<<"\t";
    }
    std::cout<<"\n";
    return mp;
}

int main() {
    std::string str{"geeksforgeeks"};
    std::map<char, int> mp{printDups(str)};
    std::cout<<mp.size()<<"\n";
    for(auto i : mp) {
        std::cout<<i.first<<" "<<i.second<<"\n";
    }
    return 0;
}