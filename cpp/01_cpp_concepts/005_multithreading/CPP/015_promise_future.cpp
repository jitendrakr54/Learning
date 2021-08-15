// DESCRIPTION :
// In this video we will learn about how std::promise and std::future and how they work together to synchronize threads.
// Basically std::promise is sent to the called thread and once the value is ready we set that value in promise object, 
// now at calling thread side we get that value using std::future object which was created using std::promise object before 
// sending it to the called thread. And this is how we receive value from one thread to another in synchronization.

#include <iostream>
#include <thread>
#include <mutex>
#include <future>

typedef long long ull;

void findOdd(std::promise<ull> &&OddSumPromis, int start, int end) {
    ull oddSum = 0;
    for(ull i=0; i<=end; i++) {
        if(i & 1) {
            oddSum += i;
        }
    }
    OddSumPromis.set_value(oddSum);
}

int main() {
    int start = 0, end = 190000000;
    std::promise<ull> oddSum;
    std::future<ull> oddFuture = oddSum.get_future();
    
    std::cout<<"Thread Created!\n";
    std::thread t(findOdd, std::move(oddSum), start, end);

    std::cout<<"Waiting for result!\n";
    std::cout<<"oddSum: "<<oddFuture.get()<<"\n";
    std::cout<<"Completed!\n";
    t.join();
    return 0;
}