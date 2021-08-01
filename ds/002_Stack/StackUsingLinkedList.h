/*
 * StckUsingLinkedList.h
 *
 *  Created on: 16-Feb-2020
 *      Author: Jitendra
 */

#pragma once

struct StackNode {
	int data;
	StackNode *link;
};

namespace ds {
namespace stack {

	class StackUsingLinkedList {
	public:
		StackUsingLinkedList();
		void push(int data);
		void pop();
		void traverse();
		void operation();
	private:
		StackNode *top;
	};
}
}
