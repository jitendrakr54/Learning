// Return number of character to be removed to make s1 and s2 anagram
#include <iostream>
#include <vector>

int makeAnagram(std::string a, std::string b) {
    auto count = 0;
    std::vector<int> freq(26, 0); // initialize 0 to all 26
    for (auto c : a) { ++freq[c - 'a']; } // 'c' - 'a' = 99 - 97 => 2, increment counter at 2nd position
    for (auto c : b) { --freq[c - 'a']; }
    for (auto val : freq) { count += abs(val); }
    return count;    
}

int main() {
    std::string a{"cde"};
    std::string b{"abc"};
    std::cout<<makeAnagram(a, b)<<"\n";
    return 0;
}