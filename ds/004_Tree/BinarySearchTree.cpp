// 1. A binary tree in which for each node, value of all the nodes in left subtree is lesser
//    and value of all the nodes in rigth subtree is greater
#include "BinarySearchTree.h"

#include <iostream>
#include <queue>

namespace ds {
namespace bst {

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

BstNode* BinarySearchTree::createNode(int data) {
	BstNode* newNode = new BstNode;
	newNode->left = nullptr;
	newNode->data = data;
	newNode->right = nullptr;
	return newNode;
}

BstNode* BinarySearchTree::insert(BstNode* root, int data) {
	if(root == nullptr) {
		root = createNode(data);
	} else if(data <= root->data) {
		root->left = insert(root->left, data);
	} else {
		root->right = insert(root->right, data);
	}
	return root;
}

bool BinarySearchTree::search(BstNode* root, int data) {
	bool found = false;
	if(root == nullptr) {
		found = false;
	} else if(data == root->data) {
		found = true;
	} else if(data <= root->data) {
		found = search(root->left, data);
	} else {
		found = search(root->right, data);
	}
	return found;
}

BstNode* BinarySearchTree::findMin(BstNode* root) {
	if(root == nullptr) {			// using iteration
		return root;
	}
	while(root->left != nullptr) {
		root = root->left;
	}
	return root;

	/*if(root == nullptr) {			// using recursion
		return -1;
	} else if(root->left == nullptr) {
		return root->data;
	} else {
		return findMin(root->left);
	}*/
}

BstNode* BinarySearchTree::findMax(BstNode* root) {

	if(root == nullptr) {			// using iteration
		return root;
	}

	while(root->right != nullptr) {
		root = root->right;
	}
	return root;

	/*if(root == nullptr) {
		return -1;
	} else if(root->right == nullptr) {
		return root->data;
	} else {
		return findMax(root->right);
	}*/
}

int BinarySearchTree::findHeight(BstNode *root) {
	if(root == nullptr) {
		return -1;
	}

	return std::max(findHeight(root->left), findHeight(root->right)) + 1;
}

void BinarySearchTree::traverseLevelOrder(BstNode* root) {
	if(root == nullptr) {
		std::cout<<"Tree is empty!"<<"\n";
		return;
	}
	std::queue<BstNode*> q;
	q.push(root);

	while(!(q.empty())) {
		BstNode *current = q.front();
		q.pop();
		std::cout<<current->data<<" ";
		if(current->left != nullptr) q.push(current->left);
		if(current->right != nullptr) q.push(current->right);
	}
	std::cout<<"\n";
}
	
void BinarySearchTree::traversePreOrder(BstNode* root) {
	if(root == nullptr) return;

	std::cout<<root->data<<" ";
	traversePreOrder(root->left);
	traversePreOrder(root->right);
}

void BinarySearchTree::traverseInOrder(BstNode* root) {
	if(root == nullptr) return;

	traverseInOrder(root->left);
	std::cout<<root->data<<" ";
	traverseInOrder(root->right);
}

void BinarySearchTree::traversePostOrder(BstNode* root) {
	if(root == nullptr) return;

	traversePostOrder(root->left);
	traversePostOrder(root->right);
	std::cout<<root->data<<" ";
}

BstNode* BinarySearchTree::del(BstNode* root, int data) {
	if(root == nullptr) {
		return root;
	} else if(data < root->data) {
		root->left = del(root->left, data);
	} else if(data > root->data) {
		root->right = del(root->right, data);
	} else {
		if(root->left == nullptr && root->right == nullptr) { //no child
			delete root;
			root = nullptr;
		} else if(root->left == nullptr) { // one child (left)
			BstNode *temp = root;
			root = root->right;
			delete temp;
		} else if(root->right == nullptr) { // right child (right)
			BstNode *temp = root;
			root = root->left;
			delete temp;
		} else {									// both child
			BstNode* temp = findMin(root->right);
			root->data = temp->data;
			root->right = del(root->right, temp->data);
		}
	}

	return root;
}

void BinarySearchTree::operation() {
	int choice;
	int data;
	bool found;
	BstNode *temp = nullptr;
	while(true) {
		std::cout<<"0. Insert \n";
		std::cout<<"1. Traverse Level order \n";
		std::cout<<"2. Traverse Pre order \n";
		std::cout<<"3. Traverse In order \n";
		std::cout<<"4. Traverse Post order \n";
		std::cout<<"5. Delete \n";
		std::cout<<"5. Search \n";
		std::cout<<"7. Minimum valued node \n";
		std::cout<<"8. Maximum valued node \n";
		std::cout<<"9. Exit \n";
		std::cin>>choice;

		switch(choice) {
		case 0:
			std::cout<<"Enter data:\n";
			std::cin>>data;
			this->root = insert(this->root, data);
			break;
		case 1:
			traverseLevelOrder(this->root);
			break;
		case 2:
			traversePreOrder(this->root);
			break;
		case 3:
			traverseInOrder(this->root);
			break;
		case 4:
			traversePostOrder(this->root);
			break;
		case 5:
			std::cout<<"Enter data to delete: \n";
			std::cin>>data;
			del(this->root, data);
			break;
		case 6:
			std::cout<<"Enter data to search: \n";
			std::cin>>data;
			found = search(this->root, data);
			if(found) {
				std::cout<<"Data found!\n";
			} else {
				std::cout<<"Data not found!\n";
			}
			break;
		case 7:
			temp = findMin(this->root);
			if(temp == nullptr) {
				std::cout<<"Tree is empty!\n";
			} else {
				std::cout<<temp->data<<"\n";
			}
			break;
		case 8:
			temp = findMax(this->root);
			if(temp == nullptr) {
				std::cout<<"Tree is empty!\n";
			} else {
				std::cout<<temp->data<<"\n";
			}
			break;
		case 9:
			exit(1);
		default:
			std::cout<<"Wrong choice!\n";
			break;
		}
	}
}

}
}


/*struct bstNode *temp;
	struct bstNode *parent = root;
//	temp = (struct bstNode*)malloc(sizeof(struct bstNode));
	temp = new bstNode;

	std::cout<<"Enter data:\n";
	std::cin>>temp->data;
	temp->left = nullptr;
	temp->right = nullptr;

	if(parent == nullptr) {
		root = temp;
	} else {
		struct bstNode *current = root;
		while(current) {
			parent = current;
			if(temp->data > current->data) {
				current = current->right;
			} else {
				current = current->left;
			}
		}
		if(temp->data > parent->data) {
			parent->right = temp;
		} else {
			parent->left = temp;
		}
	}*/

