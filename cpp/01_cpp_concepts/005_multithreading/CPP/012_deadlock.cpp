#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
std::mutex m2;

// void thread1() {
//     m1.lock();
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     m2.lock();
//     std::cout<<"Critical section of thread one\n";
//     m1.unlock();
//     m2.unlock();
// }

// void thread2() {
//     m2.lock();
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     m1.lock();
//     std::cout<<"Critical section of thread two\n";
//     m2.unlock();
//     m1.unlock();
// }

// Solution for deadlock
void thread1() {
    std::lock(m1, m2);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"Critical section of thread one\n";
    // std::unlock(m1, m2);
    m1.unlock();
    m2.unlock();
}

void thread2() {
    std::lock(m1, m2);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"Critical section of thread two\n";
    m2.unlock();
    m1.unlock();
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();
    return 0;
}