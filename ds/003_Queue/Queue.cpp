/*
 * queue.cpp
 *
 *  Created on: 17-Mar-2020
 *      Author: Jitendra
 */
#include <iostream>

#include "Queue.h"

namespace ds {
namespace queue {
	Queue::Queue(){
		rear = -1;
		front = -1;
		size = 0;
		queue = nullptr;
	}
	Queue::Queue(int size) {
		rear = -1;
		front = -1;
		this->size = size;
		queue = new int[size];
	}
	Queue::~Queue() {
		delete queue;
	}
	void Queue::push(int data) {
		if(isFull()) {
			std::cout<<"Queue is full! \n";
			return;
		} else if(isEmpty()) {
			front = 0;
			rear = 0;
		} else {
			rear++;
		}
		queue[rear] =  data;
	}

	void Queue::pop() {
		if(isEmpty()) {
			std::cout<<"Queue is empty! \n";
			return;
		} else {
			if(front == rear) {
				front = -1;
				rear = -1;
			} else {
				front++;
			}
		}
	}

	void Queue::traverse() {
		if(front == -1 && rear == -1) {
			std::cout<<"Queue is empty! \n";
		} else {
			for(int i = front; i<=rear; i++) {
				std::cout<<queue[i]<<" ";
			}
			std::cout<<"\n";
		}
	}

	bool Queue::isEmpty() {
		return (front == -1 && rear ==-1);
	}

	bool Queue::isFull() {
		return (rear == size-1);
	}

	void Queue::operation() {
		int ch;
		int data;
		while(1) {
			std::cout<<"1. Insert\n";
			std::cout<<"2. Delete\n";
			std::cout<<"3. Display\n";
			std::cout<<"4. Exit\n";

			std::cin>>ch;
			switch(ch) {
			case 1:
				std::cout<<"Enter data: \n";
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
				exit(1);
				break;
			default:
				std::cout<<"Wrong choice! \n";
				break;
			}
		}
	}
}
}


