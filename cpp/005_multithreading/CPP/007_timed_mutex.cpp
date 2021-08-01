// TOPIC: Timed Mutex In C++ Threading (std::timed_mutex)

// NOTES:
// 0. std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if success 
//    otherwise false.
// 1. Member Function:
//    a. lock 
//    b. try_lock
//    c. try_lock_for    ---\ These two functions makes it different from mutex.
//    d. try_lock_until  ---/ 
//    e. unlock

// EXAMPLE: try_lock_for();
// Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
// On successful lock acquisition returns true, otherwise returns false.

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

// int myAmount = 0;
// std::timed_mutex tm;

// void increment(int i) {
//     if(tm.try_lock_for(std::chrono::seconds(2))) {
//         ++myAmount;
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//         std::cout<<"Thread "<<i<<" entered!\n";
//         tm.unlock();
//     } else {
//         std::cout<<"Thread "<<i<<" could not enter!\n";
//     }
// }


// int main() {
//     std::thread t1(increment, 1);
//     std::thread t2(increment, 2);

//     t1.join();
//     t2.join();

//     std::cout<<myAmount<<"\n";
//     return 0;
// }

// EXAMPLE: try_lock_until
// waits until specified timeout_time has been reached or the lock is acquired, whichever comes first
// On successful lock acquisition returns true, otherwise returns false

int myAmount = 0;
std::timed_mutex tm;

void increment(int i) {
    auto now = std::chrono::steady_clock::now();
    if(tm.try_lock_until(now + std::chrono::seconds(2))) {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<"Thread "<<i<<" entered!\n";
        tm.unlock();
    } else {
        std::cout<<"Thread "<<i<<" could not enter!\n";
    }
}


int main() {
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);

    t1.join();
    t2.join();

    std::cout<<myAmount<<"\n";
    return 0;
}