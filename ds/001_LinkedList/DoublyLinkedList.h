/*
 * DoublyLinkedList.h
 *
 *  Created on: 12-Mar-2020
 *      Author: Jitendra
 */

#pragma once

struct DoubleNode {
	struct DoubleNode* prev;
	int data;
	struct DoubleNode* next;
};

namespace ds {
namespace linkedList {

	class DoublyLinkedList {
	public:
		DoublyLinkedList();
		void pushFront(int data);
		void pushBack(int data);
		void popFront();
		void popBack();
		void insert(int pos, int data);
		void erase(int pos);
		int length();
		void traverse();
		void reverseTraverse();
		void operation();
//		void getData(struct node* temp);
	private:
		struct DoubleNode *root;
	};
}
}
