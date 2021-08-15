// TOPIC: unique_lock In C++

// NOTES:
// 1. The class unique_lock is a mutex ownership wrapper.
// 2. It Allows:
//     a. Can Have Different Locking Strategies
//     b. time-constrained attempts at locking (try_lock_for, try_lock_until)
//     c. recursive locking
//     d. transfer of lock ownership (move not copy)
//     e. condition variables. (See this in coming videos)

// Locking Strategies
//    TYPE           EFFECTS(S)
// 1. defer_lock  do not acquire ownership of the mutex.
// 2. try_to_lock  try to acquire ownership of the mutex without blocking.
// 3. adopt_lock  assume the calling thread already has ownership of the mutex.

#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;
int buffer = 0;

// void task(const char* threadID, int loopFor) {
// 	std::unique_lock<std::mutex> lock(m);
// 	for(int i = 0; i<loopFor; i++) {
// 		buffer++;
// 		std::cout<<threadID<<" "<<buffer<<"\n";
// 	}
// }

void task(const char* threadID, int loopFor) {
	std::unique_lock<std::mutex> lock(m, std::defer_lock); //Does not call lock on mutex m1, because used defer_lock
    lock.lock(); // But then we will have to explicitly tell to lock whenever we want to lock mutex m1.
	for(int i = 0; i<loopFor; i++) {
		buffer++;
		std::cout<<threadID<<" "<<buffer<<"\n";
	}
    // lock.unlock(); is not require as it will be unlocked in destructor of unique_lock.
}

int main() {
    std::thread t1(task, "T0", 10);
    std::thread t2(task, "T1", 10);
    t1.join();
    t2.join();
    return 0;
}