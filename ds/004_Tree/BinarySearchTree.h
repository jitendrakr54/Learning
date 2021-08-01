/*
 * BST.h
 *
 *  Created on: 14-Apr-2020
 *      Author: Jitendra
 */

#define pragma once

struct BstNode {
	BstNode *left;
	int data;
	BstNode *right;
};

namespace ds {
namespace bst {

class BinarySearchTree {
public:
	BinarySearchTree();
	BstNode* createNode(int data);
	BstNode* insert(BstNode *root, int data);
	bool search(BstNode *root, int data);
	BstNode* findMin(BstNode *root);
	BstNode* findMax(BstNode *root);
	int findHeight(BstNode *root);
	void traverseLevelOrder(BstNode *root);
	void traversePreOrder(BstNode *root);
	void traverseInOrder(BstNode *root);
	void traversePostOrder(BstNode *root);
	struct BstNode* del(BstNode*root, int data);
	void operation();

private:
	struct BstNode *root;
};
}
}
