/*
 * TwoStack.h
 *
 *  Created on: 16-Feb-2020
 *      Author: Jitendra
 */
#pragma once

namespace ds {
namespace stack {

	class TwoStack {
	public:
		TwoStack(int n);
		~TwoStack();

		void push1(int data);
		void push2(int data);

		int pop1();
		int pop2();

	private:
		int size;
		int top1;
		int top2;
		int *arr;
	};
}
}
