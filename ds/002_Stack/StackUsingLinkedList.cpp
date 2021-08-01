/*
 * StackUsingLinkedList.cpp
 *
 *  Created on: 16-Feb-2020
 *      Author: Jitendra
 */

#include <iostream>
#include "StackUsingLinkedList.h"

namespace ds {
namespace stack {
	StackUsingLinkedList::StackUsingLinkedList():top{nullptr} {}

	void StackUsingLinkedList::push(int data) {
		StackNode* temp = new StackNode;
//		temp = (struct stackNode*)malloc(sizeof(struct stackNode));
		temp->data = data;
		temp->link = top;
		top = temp;
	}

	void StackUsingLinkedList::pop() {
		StackNode* temp = top;
		if(temp == nullptr) {
			std::cout<<"Popping not possible"<<std::endl;
		} else {
			top = temp->link;
			temp->link = nullptr;
//			free(temp);
			delete temp;
		}
	}

	void StackUsingLinkedList::traverse() {
		StackNode *temp = top;
		if(temp == nullptr) {
			std::cout<<"Stack is empty"<<std::endl;
		} else {
			std::cout<<"Stack is: "<<std::endl;
			/*for(temp = top; temp != nullptr; temp = temp->link) {
				std::cout<<temp->data<<std::endl;
			}*/
			while(temp != nullptr) {
				std::cout<<temp->data<<std::endl;
				temp = temp->link;
			}
		}
	}

	void StackUsingLinkedList::operation() {
		int ch;
		while(1) {
			std::cout<<"1. Push"<<std::endl;
			std::cout<<"2. Pop"<<std::endl;
			std::cout<<"3. Traverse"<<std::endl;
			std::cout<<"4. Quit"<<std::endl;

			std::cout<<"Enter ur choice"<<std::endl;
			std::cin>>ch;

			int data;

			switch(ch) {
				case 1:
					std::cout<<"Enter data"<<std::endl;
					std::cin>>data;
					push(data);
					break;
				case 2:
					pop();
					break;
				case 3:
					traverse();
					break;
				case 4:
					exit(0);
					break;
				default:
					std::cout<<"Invalid choice"<<std::endl;
					break;
			}
		}
	}
}
}

