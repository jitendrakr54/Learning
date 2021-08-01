// TOPIC: std::mutex::try_lock() On Mutex In C++11 Threading

// 0. try_lock() Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true
//    otherwise returns false.
// 1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called 
//    non-blocking.
// 2. If try_lock is called again by the same thread which owns the mutex, the behavior is undefined.
//    It is a dead lock situation with undefined behavior. (if you want to be able to lock the same mutex
//    by same thread more than one time the go for recursive_mutex)

// There are so many try_lock function
// 1. std::try_lock
// 2. std::mutex::try_lock
// 3. std::shared_lock::try_lock
// 4. std::timed_mutex::try_lock
// 5. std::unique_lock::try_lock
// 6. std::shared_mutex::try_lock
// 7. std::recursive_mutex::try_lock
// 8. std::shared_timed_mutex::try_lock
// 9. std::recursive_timed_mutex::try_lock

#include <iostream>
#include <thread>
#include <mutex>

int counter=0;
std::mutex mtx;

void increaseCounter100000Times() {
    for(int i=0; i<100000; ++i) {
        // mtx.lock();
        if(mtx.try_lock()) {
            ++counter;
            mtx.unlock();
        }
    }
}

int main() {
    std::thread t1(increaseCounter100000Times);
    std::thread t2(increaseCounter100000Times);

    t1.join();
    t2.join();

    std::cout<<"Counter could increases upto : "<<counter<<"\n";
    return 0;
}
