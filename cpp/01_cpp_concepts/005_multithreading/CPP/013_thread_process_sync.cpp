// TOPIC: Thread OR Process Synchronization

// NOTE: we will use only thread examples to explain this topic.

// POINTS:
// 1.0 Thread Or Process synchronize to access critical section.
// 2.0 Critical section is one or collection of program statements which should be executed by only one thread or 
//     process at a time.

#include <iostream>
#include <thread>
#include <mutex>

long long bankBalance = 0;
std::mutex m;
void addMoney(long long val) {
    m.lock();
    bankBalance += val;
    m.unlock();
}

int main() {
    std::thread t1(addMoney, 100);
    std::thread t2(addMoney, 200);

    t1.join();
    t2.join();

    std::cout<<"Final Bankbalance : "<< bankBalance <<"\n";
    return 0;
}
