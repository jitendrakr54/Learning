/*
 * CircularQueue.h
 *
 *  Created on: 24-Nov-2020
 *      Author: Jitendra
 */

#pragma once

namespace ds {
namespace queue {
	class CircularQueue {
	public:
		CircularQueue();
		CircularQueue(int size);
		virtual ~CircularQueue();
		virtual void enqueue(int data);
		virtual void dequeue();
		virtual void traverse();
		virtual void operation();
		bool isEmpty();
		bool isFull();
	private:
		int front;
		int rear;
		int size;
		int *queue;
	};
}
}
