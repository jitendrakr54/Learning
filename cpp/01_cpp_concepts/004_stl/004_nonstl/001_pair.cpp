// TOPIC: std::pair in C++

// SYNTAX:
// std::pair<T1, T2> obj;

// NOTES:
// 0. std::pair is a struct template that provides a way to store two heterogeneous objects as a single unit.
// 1. map, multimap, unorder_map, unorder_multimap can use pair to insert data into their structures.

#include <iostream>
#include <vector>

void print(std::pair<int, int>& obj) {std::cout<<obj.first<<" "<<obj.second<<"\n";}

int main() {
    {
        std::pair<int, int> obj(10, 20);
        print(obj);
    }

    {
        std::pair<int, int> obj = std::make_pair(10, 20);
        print(obj);
    }

    {
        std::vector<std::pair<std::string, int>> list;
        list.push_back(std::make_pair("Jitendra", 27));
        list.push_back(std::make_pair("Khush", 26));
        list.push_back(std::pair<std::string, int>("Prince", 25));
        // list.push_back(std::pair("Sonu", 28));

        for(auto& elm : list) {
            std::cout<<elm.first<<" "<<elm.second<<"\n";
        }
    }
    return 0;
}