/*
 * DoublyLinkedList.cpp
 *
 *  Created on: 12-Mar-2020
 *      Author: Jitendra
 */
#include <iostream>
#include "DoublyLinkedList.h"

namespace ds {
namespace linkedList {

	DoublyLinkedList::DoublyLinkedList() {
		root = nullptr;
	}

	void DoublyLinkedList::pushFront(int data) {
		DoubleNode* temp = new DoubleNode;

		temp->data = data;
		temp->prev = nullptr;
		temp->next = nullptr;

		if(root == nullptr) {
			root = temp;
		} else {
			temp->next = root;
			root->prev = temp;
			root = temp;
		}
	}

	void DoublyLinkedList::pushBack(int data) {
		DoubleNode* temp = new DoubleNode;

		temp->data = data;
		temp->prev = nullptr;
		temp->next = nullptr;

		if(root == nullptr) {
			root = temp;
		} else {
			struct DoubleNode* p = root;
			while(p->next) {
				p = p->next;
			}
			p->next = temp;
			temp->prev = p;
		}
	}

	void DoublyLinkedList::insert(int pos, int data) {

		int len = length();
		if(pos > len) {
			std::cout<<"Invalid position!!\n";
			return;
		}

		DoubleNode* temp = new DoubleNode;
		temp->prev = nullptr;
		temp->data = data;
		temp->next = nullptr;

		if(pos == 1) {
			temp->next = root;
			if(root) {
				temp->next->prev = temp;
			}
			root = temp;
		} else {
			DoubleNode* p = root;
			for(int i=0; i<pos-2; i++) {
				p = p->next;
			}
			temp->next = p->next;
			p->next->prev = temp;
			temp->prev = p;
			p->next = temp;
		}
	}

	void DoublyLinkedList::popFront() {
		DoubleNode* temp = root;

		if(temp == nullptr) {
			std::cout<<"List is empty"<<std::endl;
		} else if(temp->next == nullptr) {
			root = nullptr;
			delete temp;
		} else {
			root = temp->next;
			temp->next->prev = nullptr;
			temp->next = nullptr;
			delete temp;
		}
	}

	void DoublyLinkedList::popBack() {
		struct DoubleNode* temp = root;

		if(temp == nullptr) {
			std::cout<<"List is empty"<<std::endl;
		} else if(temp->next == nullptr) {
			root = nullptr;
			delete temp;
		} else {
			struct DoubleNode *p,*q;
			p = root;
			while(p->next->next) {
				p = p->next;
			}
			q = p->next;
			p->next = nullptr;
			q->prev = nullptr;
			delete q;
		}
	}

	void DoublyLinkedList::erase(int pos) {
		struct DoubleNode* temp = root;
		int len = length();
		if(pos>len) {
			std::cout<<"Invalid location!\n";
			std::cout<<"Currently list id having "<<len<< " node\n";
			return;
		} else if(temp == nullptr) {
			std::cout<<"List is empty!\n";
			return;
		} else if (temp->next == nullptr) {
			root = nullptr;
			delete temp;
		} else if(pos == 1) {
			root = temp->next;
			temp->next->prev = nullptr;
			temp->next = nullptr;
			delete temp;
		} else {
			struct DoubleNode* p = root;
			for(int i=0; i<pos-2; i++) {
				p = p->next;
			}
			struct DoubleNode* q = p->next;
			if(q->next) {
				p->next = q->next;
				q->next->prev = p;
				q->next = nullptr;
				q->prev = nullptr;
				delete q;
				return;
			}
			p->next = nullptr;
			q->prev = nullptr;
			delete q;
		}
	}

	int DoublyLinkedList::length() {
		struct DoubleNode* p = root;
		int count = 0;

		while (p) {
			count++;
			p = p->next;
		}
		return count;
	}

	void DoublyLinkedList::traverse() {
		struct DoubleNode *temp = root;
		if(temp == nullptr) {
			std::cout<<"List is empty"<<std::endl;
			return;
		}
		while(temp) {
			std::cout<<temp->data<<"->";
			temp = temp->next;
		}
		std::cout<<"\n";
	}

	void DoublyLinkedList::reverseTraverse() {
		struct DoubleNode *temp = root;
		if(temp == nullptr) {
			std::cout<<"List is empty"<<std::endl;
			return;
		}
		while(temp->next) {
			temp = temp->next;
		}
		std::cout<<"Reverse: ";
		while(temp) {
			std::cout<<temp->data<<" ";
			temp = temp->prev;
		}
		std::cout<<"\n";
	}

	void DoublyLinkedList::operation() {
		int ch;
		int pos, data;
		while(1) {
			std::cout<<"1. Push front \n";
			std::cout<<"2. Push back \n";
			std::cout<<"3. Insert \n";
			std::cout<<"4. Pop front \n";
			std::cout<<"5. Pop back \n";
			std::cout<<"6. Delete \n";
			std::cout<<"7. Display \n";
			std::cout<<"8. Reverse Display \n";
			std::cout<<"9. Exit \n\n";

			std::cout<<"Enter your choice: \n";
			std::cin>>ch;

			switch(ch) {
			case 1:
				std::cout<<"Enter data: \n";
				std::cin>>data;
				pushFront(data);
				break;
			case 2:
				std::cout<<"Enter data: \n";
				std::cin>>data;
				pushBack(data);
				break;
			case 3:
				std::cout<<"Enter position and data: \n";
				std::cin>>pos>>data;
				insert(pos, data);
				break;
			case 4:
				popFront();
				break;
			case 5:
				popBack();
				break;
			case 6:
				std::cout<<"Enter position to delete: \n";
				std::cin>>pos;
				erase(pos);
				break;
			case 7:
				traverse();
				break;
			case 8:
				reverseTraverse();
				break;
			case 9:
				exit(1);
			default:
				std::cout<<"Wrong choice! \n";
				break;
			}
		}
	}
}
}


