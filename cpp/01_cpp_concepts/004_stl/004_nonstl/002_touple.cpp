// TOPIC: std::Tuple in C++

// SYNTAX:
//  tuple<T1, T2, T3> tuple1;

// EXAMPLE:
//   tuple<string, int, int> t1;

// NOTES:
//  0. Just like in pair, we can pair two hetrogeneous objects, in tuple we can pair multiple objects.
//  std::make_tuple();

// MEMBER FUNCTIONS
//    (constructor), operator=, swap

// NON-MEMBER FUNCTIONS
//    make_tuple(), tie(), forward_as_tuple(), tuple_cat(), std::get(std::tuple)


#include <iostream>
#include <tuple>

// int main() {
//     std::tuple<std::string, int, int> t1;
//     t1=std::make_tuple("Rahul", 15, 30);
//     std::cout<<std::get<0>(t1)<<" ";
//     std::cout<<std::get<1>(t1)<<" ";
//     std::cout<<std::get<2>(t1)<<" ";
//     return 0;
// }


std::tuple<double, char, std::string> get_student(int id)
{
    if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
    if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
    if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
    throw std::invalid_argument("id");
}
 
int main()
{
    auto student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << std::get<0>(student0) << ", "
              << "grade: " << std::get<1>(student0) << ", "
              << "name: " << std::get<2>(student0) << '\n';
 
    double gpa1;
    char grade1;
    std::string name1;
    std::tie(gpa1, grade1, name1) = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << gpa1 << ", "
              << "grade: " << grade1 << ", "
              << "name: " << name1 << '\n';
 
    // C++17 structured binding:
    auto [ gpa2, grade2, name2 ] = get_student(2);
    std::cout << "ID: 2, "
              << "GPA: " << gpa2 << ", "
              << "grade: " << grade2 << ", "
              << "name: " << name2 << '\n';
}