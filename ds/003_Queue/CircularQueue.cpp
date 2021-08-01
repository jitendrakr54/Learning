/*
 * CircularQueue.cpp
 *
 *  Created on: 24-Nov-2020
 *      Author: Jitendra
 */

#include <iostream>

#include "CircularQueue.h"

namespace ds {
namespace queue {

CircularQueue::CircularQueue() {
		rear = -1;
		front = -1;
		size = 0;
		queue = nullptr;
}

CircularQueue::CircularQueue(int size) {
		rear = -1;
		front = -1;
		this->size = size;
		queue = new int[size];
}

CircularQueue::~CircularQueue() {
		delete queue;
}

void CircularQueue::enqueue(int data) {
	if(isFull()) {
		std::cout<<"Queue is full! \n";
		return;
	} else if(isEmpty()) {
		front = 0;
		rear = 0;
	} else {
		rear = (rear+1)%size;
	}
	queue[rear] =  data;
}

void CircularQueue::dequeue() {
	if(isEmpty()) {
		std::cout<<"Queue is empty! \n";
		return;
	} else {
		if(front == rear) {
			front = -1;
			rear = -1;
		} else {
			front = (front+1)%size;
		}
	}
}

void CircularQueue::traverse() {
	if(isEmpty()) {
		std::cout<<"Queue is empty! \n";
	}
	// Finding number of elements in queue
	int count = (rear+size-front)%size + 1;
	std::cout<<"Queue       : ";
	for(int i = 0; i <count; i++)
	{
		int index = (front+i) % size; // Index of element while travesing circularly from front
		std::cout<<queue[index]<<" ";
	}
	std::cout<<"\n\n";
}

bool CircularQueue::isEmpty() {
	return (front == -1 && rear ==-1);
}

bool CircularQueue::isFull() {
	return (rear+1)%size == front ? true : false;
}

void CircularQueue::operation() {
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
			enqueue(data);
			break;
		case 2:
			dequeue();
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


