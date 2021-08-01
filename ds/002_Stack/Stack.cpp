/*
 * Stack.cpp
 *
 *  Created on: 16-Feb-2020
 *      Author: Jitendra
 */

#include <iostream>
#include "Stack.h"

using namespace std;

namespace ds {
namespace stack {

	Stack::Stack(int n) : size{n}, top{-1} {
		arr = new int[size];
	}

	Stack::~Stack() {
		delete arr;
	}
	void Stack::push(int data) {
		if(isFull()) {
			std::cout<<"Stack is overflow"<<endl;
			return;
		}
		arr[++top] = data;
	}

	int Stack::pop() {
		if(isEmpty()) {
			std::cout<<"Stack is empty"<<endl;
			return -1;
		}
		return arr[top--];
	}

	bool Stack::isFull() {
		return (top == (size - 1));
	}

	bool Stack::isEmpty() {
		return (top < 0);
	}

	int Stack::peek() {
		return arr[top];
	}

	void Stack::traverse() {
		for(int i = top; i>=0; i--) {
			std::cout<<arr[i]<<endl;
		}
	}

	void Stack::operation() {
		int ch;
		int data;
		while(1) {
			std::cout<<"Please make a selection"<<endl;
			std::cout<<"1. To push"<<endl;
			std::cout<<"2. To pop"<<endl;
			std::cout<<"3. To print"<<endl;
			std::cout<<"4. To quit"<<endl;
			std::cin>>ch;
			switch(ch) {
				case 1: {
					std::cout<<"Enter data to push"<<endl;
					std::cin>>data;
					push(data);
					break;
				}
				case 2: {
					int poppedElement = pop();
					if(poppedElement) {
						std::cout<<"Popped data: "<<poppedElement<<"\n";
					}
					break;
				}
				case 3: {
					traverse();
					break;
				}
				case 4: {
					exit(1);
				}
				default: {
					std::cout<<"Invalid selection!!";
					break;
				}
			}
		}
	}
}
}


