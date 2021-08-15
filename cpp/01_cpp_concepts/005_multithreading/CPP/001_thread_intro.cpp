// Introduction to thread in c++ (c++11), introduced in C++11
// QUESTIONS
// 1. What do you understand by thread and give one example in C++?

// ANSWER
//  A thread is a path of execution within a process. A process can contain multiple threads
// 0. In every application there is a default thread which is main(), in side this we create other threads.
// 1. A thread is also known as lightweight process. Idea is to achieve parallelism by dividing a process
//    into multiple threads. 
//    For example:
//    (a) The browser has multiple tabs that can be different threads. 
//    (b) MS Word must be using multiple threads, one thread to format the text, another thread to process
//        inputs (spell checker)
//    (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

// WAYS TO CREATE THREADS IN C++11
// 1. Function Pointers
// 2. Lambda Functions
// 3. Functors
// 4. Member Functions
// 5. Static Member functions

// Thread safety:
// A function is said to be thread-safe if and only if it will always produce correct results when called
// repeatedly from multile concurrent threads.

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

	findEvenSum(start, end, &evenSum);
	findOddSum(start, end, &oddSum);
	
	auto endTime = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
	std::cout<<"evenSum: "<<evenSum<<std::endl;
	std::cout<<"oddSum: "<<oddSum<<std::endl;
//	std::cout<<duration.count()/1000000<<" Seconds"<<std::endl;
	std::cout<<duration.count()<<" Seconds"<<std::endl;
}

