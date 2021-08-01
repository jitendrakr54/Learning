/*
 * LinkedQueue.h
 *
 *  Created on: 20-Mar-2020
 *      Author: Jitendra
 */
#pragma once

#include "Queue.h"

struct QNode {
	int data;
	QNode *link;
};

namespace ds {
namespace queue {

class LinkedQueue : public Queue {
public:
	LinkedQueue();
	virtual ~LinkedQueue();
	virtual void push(int data);
	virtual void pop();
	void traverse();

private:
	QNode *front;
	QNode *rear;
};
}
}
