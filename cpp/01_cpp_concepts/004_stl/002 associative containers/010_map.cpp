// 1. std::map is associative container that contains a sorted list of key-value pairs with unique keys.
// 2. It is implemented using Self-Balance Binary Search Tree (AVL/Red Black Tree) .
// 3. It store key value pair in sorted order on the basis of key (assending/decending).
// 4. std::map is generally used in Dictionay type problems.
// 5. Search, removal, and insertion operations have logarithmic complexity.

// ELEMENT ACCESS:
//    at(), operator[]

// ITERATORS:
//     begin(), cbegin(), end(), cend(), rbegin(), crbegin(), rend(), crend()

// CAPACITY:
//      empty(), size(), max_size()

// MODIFIERS:
//      insert(), insert_or_assign(), emplace(), emplace_hint(), try_emplace(), swap(), erase(), clear(), 
//      extract(), merge()

// LOOKUP:
//      count(), find(), contains(), equal_range(), lower_bound(), upper_bound()

// OBSERVERS:
//      key_comp(), value_comp()

// lower_bound() : The function returns an iterator pointing to the key in the map container which is equivalent to k passed
// in the parameter. In case k is not present in the map container, the function returns an iterator pointing to the immediate
// next element which is just greater than k. If the key passed in the parameter exceeds the maximum key in the container, 
// then the returned iterator points to the number of elements in the map as key and element= any element. 

//If the passed parameter exceeds the maximum key in the container, then returned iterator will point to the map::end() like in std::set.

// upper_bound() :  The function returns an iterator pointing to the immediate next element which is just greater than k. 
// If the key passed in the parameter exceeds the maximum key in the container, then returned iterator points to map_name.end().
// Note that end() is a special iterator that does not store address of a valid member of a map.

#include <algorithm>
#include <iostream>
#include <map>

int main() {
    // std::map<std::string, std::string, std::greater<>> mp{{"Jit", "782813048"}, {"Khush", "8269620258"}};
    // mp.insert(std::make_pair("Kumar", "9074284789"));
    // mp.insert(std::make_pair("Kumar", "8034974923"));
    // mp.insert_or_assign("Khush", "826933620259");
    // // mp.insert("Ram", "826933620258");
    // for(const auto &ele: mp) {
    //     std::cout<<ele.first<<" "<<ele.second<<"\n";
    // }

    std::map<int, int> mp;
    // insert elements in random order
    mp.insert({ 2, 30 });
    mp.insert({ 1, 10 });
    mp.insert({ 5, 50 });
    mp.insert({ 4, 40 });
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        std::cout << (*it).first << " " <<(*it).second << std::endl;
    }
 
    // when 2 is present
    auto it = mp.lower_bound(2);
    std::cout << "The lower bound of key  is ";
    std::cout << (*it).first << " " << (*it).second << std::endl;
 
    // when 3 is not present
    // points to next greater after 3
    it = mp.lower_bound(3);
    std::cout << "The lower bound of key 3 is ";
    std::cout << (*it).first << " " << (*it).second;
 
    // when 6 exceeds
    it = mp.lower_bound(6);
    std::cout << "\nThe lower bound of key 6 is ";
    std::cout << (*it).first << " " << (*it).second;

    // insert elements in random order
    // mp.insert({ 12, 30 });
    // mp.insert({ 11, 10 });
    // mp.insert({ 15, 50 });
    // mp.insert({ 14, 40 });
    // for (auto it = mp.begin(); it != mp.end(); it++)
    // {
    //     std::cout << (*it).first << " " <<(*it).second << std::endl;
    // }
    // // when 11 is present
    // auto it = mp.upper_bound(11);
    // std::cout << "The upper bound of key 11 is ";
    // std::cout << (*it).first << " " << (*it).second << std::endl;
  
    // // when 13 is not present
    // it = mp.upper_bound(13);
    // std::cout << "The upper bound of key 13 is ";
    // std::cout << (*it).first << " " << (*it).second << std::endl;
  
    // // when 17 is exceeds the maximum key, so size
    //     // of mp is returned as key and value as 0.
    // it = mp.upper_bound(17);
    // std::cout << "The upper bound of key 17 is ";
    // std::cout << (*it).first << " " << (*it).second;

    return 0;
}