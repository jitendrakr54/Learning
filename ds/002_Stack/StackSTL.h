/*
 * StackSTL.h
 *
 *  Created on: 04-Nov-2020
 *      Author: Jitendra
 */

#pragma once

#include <iostream>
#include <cassert>

namespace ds {
namespace stack {

template<class T>
	class StackSTL {
	private:
		int size{};
		int top;
		T *arr{};
	public:
		StackSTL(int length) : size{length}, top{-1}{
			assert( size > 0 );
			arr = new T[size];
		}
		~StackSTL() { delete[] arr; }
		void push(T data) {
			if(isFull()) {
				std::cout<<"Stack is overflow! \n";
				return;
			}
			arr[++top] = data;
		}
		T pop() {
			if(isEmpty()) {
				std::cout<<"Stack is empty! \n";
				exit(0);
			}
			return arr[top--];
		}
		bool isEmpty() {
			return top == -1;
		}
		bool isFull() {
			return top == size-1;
		}
		T peek() {
			return arr[top];
		}
	};
}
}
