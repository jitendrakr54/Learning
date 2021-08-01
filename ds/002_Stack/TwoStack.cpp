/*
 * TwoStack.cpp
 *
 *  Created on: 16-Feb-2020
 *      Author: Jitendra
 */
#include <iostream>
#include "TwoStack.h"

using namespace std;

namespace ds {
namespace stack {
	TwoStack::TwoStack(int n) : size{n}, top1{-1}, top2{size} {
		arr = new int[size];
	}

	TwoStack::~TwoStack() {
		delete arr;
	}

	void TwoStack::push1(int data) {
		if(top1 < top2-1) {
			arr[++top1] = data;
		} else {
			std::cout<<"Stack overflow"<<endl;
		}
	}

	void TwoStack::push2(int data) {
		if(top1 < top2-1) {
			arr[--top2] = data;
		} else {
			std::cout<<"Stack overflow"<<endl;
		}
	}

	int TwoStack::pop1() {
		if(top1 >= 0) {
			return arr[top1--];
		} else {
			std::cout<<"Stack underflow"<<endl;
			exit(1);
		}
	}

	int TwoStack::pop2() {
		if(top2 < size) {
			return arr[top2++];
		} else {
			std::cout<<"Stack underflow"<<endl;
			exit(1);
		}
	}
}
}



