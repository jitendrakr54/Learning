/*
 * queue.h
 *
 *  Created on: 17-Mar-2020
 *      Author: Jitendra
 */
#pragma once

namespace ds {
namespace queue {
	class Queue {
	public:
		Queue();
		Queue(int size);
		virtual ~Queue();
		virtual void push(int data);
		virtual void pop();
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
