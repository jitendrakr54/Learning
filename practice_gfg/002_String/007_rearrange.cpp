// Jitendra3 gupta5 i1 am2 kumar4
#include <iostream>
#include <vector>
#include <map>

std::string reArrange(std::string str) {
    std::map<int, std::string> vec;
    int j = 0;
    str.append(" ");
    for(int i=0; i<str.length(); i++) {
        if(str[i] == ' ') {
            int pos = str[i-1] - '0';
            vec[pos] = std::string(str.begin()+j, str.begin()+i-1) + " ";
            j = i+1;
        }
    }
    std::cout<<vec.size()<<"\n";
    std::string output{};
    for(auto it = vec.begin(); it != vec.end(); it++) {
        output.append(it->second);
    }
    return output;
}

int main() {
    std::string input = "Jitendra3 gupta5 i1 am2 kumar4";
    std::cout<<reArrange(input)<<"\n";
}
