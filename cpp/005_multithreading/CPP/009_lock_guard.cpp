// TOPIC: std::lock_guard In C++
 
// NOTES:
// 0. It is very light weight wrapper for owning mutex on scoped basis.
// 1. It acquires mutex lock the moment you create the object of lock_guard.
// 2. It automatically removes the lock while goes out of scope.
// 3. You can not explicitly unlock the lock_guard.
// 4. You can not copy lock_guard.

#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;
int buffer = 0;

void task(const char* threadID, int loopFor) {
	std::lock_guard<std::mutex> lock(m);
	for(int i = 0; i<loopFor; i++) {
		buffer++;
		std::cout<<threadID<<" "<<buffer<<"\n";
	}
}

int main() {
    std::thread t1(task, "T0", 10);
    std::thread t2(task, "T1", 10);
    t1.join();
    t2.join();
    return 0;
}