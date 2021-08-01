/*
 * nodes.h
 *
 *  Created on: 12-Mar-2020
 *      Author: Jitendra
 */

#pragma once

namespace ds {
namespace nodes {

struct singleNode {
	int data;
	struct singleNode* link;
};

struct doubleNode {
	struct doubleNode* left;
	int data;
	struct doubleNode* right;
};

struct stackNode {
	int data;
	struct stackNode *link;
};

}
}
