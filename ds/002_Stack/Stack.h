/*
 * Stack.h
 *
 *  Created on: 16-Feb-2020
 *      Author: Jitendra
 */

#pragma once

namespace ds {
namespace stack {
	class Stack {
	public:
		Stack(int n);
		~Stack();
		void push(int data);
		int pop();
		bool isEmpty();
		bool isFull();
		int peek();
		void traverse();
		void operation();
	private:
		int size;
		int top;
		int *arr;
	};
}
}

