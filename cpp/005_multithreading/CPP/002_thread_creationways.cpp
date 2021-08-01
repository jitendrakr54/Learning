// TOPIC: Different Types Of Thread Creation And Calling.
// There are 5 different types of creating threads and calling callable in threads.

// If we create multiple threads at the same time it doesn't guarantee which one will start first.

// NOTES: Different types for creating threads.
// 1. Function Pointer -- this is the very basic form of creating threads.
// 2. Lambda Function
// 3. Functor (Function Object)
// 4. Non-static member function
// 5. Static member function

// There are more than listed ways to create threads but for now we will learn this much.

#include <iostream>
#include <thread>

// 1. Function Pointer -- this is the very basic form of creating threads.
// void fun(int x) {
//     while(x-->0) {
//         std::cout<<x<<"\n";
//     }
// }
// int main() {
//     std::thread t1(fun, 11);
//     t1.join();
//     return 0;
// }


// 2. Lambda Function
// int main() {
//     // auto fun = [](int x) {
//     //     while(x-->0) {
//     //         std::cout<<x<<"\n";
//     //     }
//     // };
//     // std::thread t(fun, 10);
//     // t.join();
//     std::thread t([](int x) {
//         while(x --> 0) {
//             std::cout<<x<<"\n";
//         }
//     }, 11);
//     t.join();
//     return 0;
// }


// 3. Functor (Function Object)
// class Base {
//     public:
//         void operator()(int x) {
//             while( x --> 0) {
//                 std::cout<<x<<"\n";
//             }
//         }
// };
// int main() {
//     std::thread t((Base()), 10);
//     t.join();
//     return 0;
// }


// 4. Non-static member function
// class Base {
//     public:
//         void run(int x) {
//             while( x --> 0) {
//                 std::cout<<x<<"\n";
//             }
//         }
// };
// int main() {
//     Base b;
//     std::thread t(&Base::run, &b, 11);
//     t.join();
//     return 0;
// }


// 5. Static member function
class Base {
    public:
        static void run(int x) {
            while( x --> 0) {
                std::cout<<x<<"\n";
            }
        }
};
int main() {
    std::thread t(&Base::run, 11);
    t.join();
    return 0;
}

