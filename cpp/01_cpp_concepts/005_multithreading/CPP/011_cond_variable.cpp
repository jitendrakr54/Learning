// TOPIC: Condition Variable In C++ Threading

// IMPORTANT POINT: CV are used for two purpose
// A. notify other threads
// B. Waiting for some condition

// NOTES:
// 1. Condition variables allow running threads to wait on some conditions and once those conditions
//    are met, the waiting thread is notified using:
//      a. notify_one();
//      b. notify_all();
// 2. You need mutex to use condition variable
// 3. If some thread want to wait on some condition then it has to do these things:
//      a. Acquire the mutex lock using std::unique_lock<std::mutex> lock(m);
//      b. Execute wait, wait_for, or wait_until. The wait operations automatically release the mutex
//          and suspend the execution of the thread.
//      c. When the condition variable is notified, the thread is awakened, and the mutex is automatically re-acquired.
//          The thread should then check the condition and resume waiting if the wakeup was spurious.

// NOTES:
// 1. Condition variable is used to synchronize two or more threads.
// 2. Best use case of condition variable is Producer/Consumer problem.


#include <chrono>
#include <condition_variable>
#include <iostream>
#include <thread>

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money) {
	std::lock_guard<std::mutex> lock(m);
	balance += money;
	std::cout<<"Amount added! Current balance is: "<<balance<<"\n";
	cv.notify_one();
}

void withDrawMoney(int money) {
	std::unique_lock<std::mutex> lock(m);
	cv.wait(lock, [] { return (balance != 0) ? true : false; });

	if(balance >= money) {
		balance -= money;
		std::cout<<"Money deducted: "<<money<<"\n";
	} else {
		std::cout<<"Money can't be deducted! Current balance is less than "<<money<<"\n";
	}
	std::cout<<"Current balance is: "<<balance<<"\n";
}

int main() {
    std::thread t1(withDrawMoney, 600);
    std::thread t2(addMoney, 500);
    t1.join();
    t2.join();
    return 0;
}