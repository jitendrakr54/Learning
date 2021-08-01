#include <chrono>
#include <iostream>
#include <thread>

typedef unsigned long long ull;

void findEvenSum(ull start, ull end, ull* evenSum) {
	for(ull i = start; i <= end; i++) {
		if((i & 1) == 0) {
			*evenSum += i;
		}
	}
}

void findOddSum(ull start, ull end, ull* oddSum) {
	for(ull i = start; i <= end; i++) {
		if((i & 1) == 1) {
			*oddSum += i;
		}
	}
}

int main() {
    ull start = 0, end = 1900000000;
    ull evenSum = 0, oddSum = 0;
    
	auto startTime = std::chrono::high_resolution_clock::now();

	std::thread t1(findEvenSum, start, end, &evenSum);
	std::thread t2(findOddSum, start, end, &oddSum);
	
	t1.join();
	t2.join();

	auto stopTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);

	std::cout<<"evenSum: "<<evenSum<<std::endl;
	std::cout<<"oddSum: "<<oddSum<<std::endl;

	std::cout<<duration.count()<<" Seconds"<<std::endl;

    return 0;
}
