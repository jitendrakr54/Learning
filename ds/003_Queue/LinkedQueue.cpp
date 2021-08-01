/*
 * LinkedQueue.cpp
 *
 *  Created on: 20-Mar-2020
 *      Author: Jitendra
 */

#include "LinkedQueue.h"
#include <iostream>

namespace ds {
namespace queue {

LinkedQueue::LinkedQueue() : Queue(){
	front = nullptr;
	rear = nullptr;
}

LinkedQueue::~LinkedQueue() {
	delete front;
	delete rear;
}

void LinkedQueue::push(int data) {
	QNode *temp = new QNode;
	temp->data = data;
	temp->link = nullptr;

	if(front == nullptr) {
		front = temp;
		rear = temp;
	} else {
		rear->link = temp;
		rear = temp;
	}
}

void LinkedQueue::pop() {
	if(front == nullptr) {
		std::cout<<"Queue is empty ! \n";
	} else {
		QNode *temp = front;
		front = temp->link;
		temp->link = nullptr;
//		free(temp);
		delete temp;
	}
}

void LinkedQueue::traverse() {
	if(front == nullptr) {
		std::cout<<"Queue is empty! \n";
	} else {
		QNode *temp = front;
		/*for(temp = front; temp!=rear; temp=temp->link) {
			std::cout<<temp->data<<"->";
		}*/
		while(temp) {
			std::cout<<temp->data<<"->";
			temp=temp->link;
		}
		std::cout<<"\n";
	}
}
}
}


