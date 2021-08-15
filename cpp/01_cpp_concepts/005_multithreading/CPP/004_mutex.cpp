// TOPIC: Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It? | What Is Critical Section

// Mutex: Mutual Exclusion

// RACE CONDITION:
// 0. Race condition is a situation where several threads/process happens to change a common data at the
//    same time.
// 1. If there is a race condition then we have to protect it and the protected section is called critical
//    section/region.

// MUTEX:
// 0. Mutex is used to avoid race condition.
// 1. We use lock() , unlock() on mutex to avoid race condition.

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

int myAmount = 0;
std::mutex m;

void addMoney() {
    m.lock();
    ++myAmount;             // Critical section
    m.unlock();
}

int main() {
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    std::cout<< myAmount<<"\n";
}