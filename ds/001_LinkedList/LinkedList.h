/*
 * LinkedList.h
 *
 *  Created on: 16-Feb-2020
 *      Author: Jitendra
 */

#pragma once

struct SingleNode {
	int data;
	SingleNode* next;
};

namespace ds {
namespace linkedList {

	class LinkedList {
	public:
		LinkedList();
//		void pushBack(int data);
//		void popBack();
		void pushFront(int data);
		void popFront();
		void insert(int pos, int data);
		int findKthFromLast(int pos);
		void erase(int pos);
		int length();
		void traverse();
		void swap(int pos);
		void reverse();
		void operation();

	private:
		SingleNode *root;
	};
}
}
