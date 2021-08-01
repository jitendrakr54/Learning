/*
 * LinkedList.cpp
 *
 *  Created on: 16-Feb-2020
 *      Author: Jitendra
 */

// Q. 	How do we know that two list has intersection point
// Ans: We can move both of the list to last point and store last point in temp then we can compare if both address
// 		are same then we can conclude that both have an intersection point

#include <iostream>

struct SingleNode {
	int data;
	SingleNode* next;
};

class LinkedList {
	private:
		SingleNode *root;
	public:
	LinkedList() : root{nullptr} {}

	/*void LinkedList::pushBack(int data) {
		SingleNode *temp = new SingleNode();               // temp = (SingleNode*)malloc(sizeof(SingleNode));
		temp->data = data;
		temp->link = nullptr;

		if(root == nullptr) {
			root = temp;
		} else {
			SingleNode *p = root;
			while(p->link) {
				p = p->link;
			}
			p->link = temp;
		}
	}*/

	void pushFront(int data) {
		SingleNode *temp = new SingleNode();
		temp->data = data;
		temp->next = nullptr;

		if(root == nullptr) {
			root = temp;
		} else {
			temp->next = root;
			root = temp;
		}
	}

	/*void popBack() {
		erase(length());
		SingleNode *temp = root;
		if(temp == nullptr) {
			std::cout<<"List is empty! \n";
		} else if(temp->link == nullptr) {
			root = nullptr;
			delete temp;                                    // free(temp);
		} else {
			SingleNode *temp1, *temp2;
			temp1 = root;
			while(temp1->link->link) {
				temp1 = temp1->link;
			}
			temp2 = temp1->link;
			temp1->link = nullptr;
			delete temp2;
		}
	}*/

	void popFront() {
		SingleNode *temp;
		temp = root;
		if(temp == nullptr) {
			std::cout<<"List is empty \n";
		} else if(temp->next == nullptr) {
			root = nullptr;
			delete temp;
		} else {
			root = temp->next;
			temp->next = nullptr;
			delete temp;
		}
	}

	void insert(int pos, int data) {
		int len = length();
		if(pos > len) {
			std::cout<<"Invalid node! \n";
			std::cout<<"Currently list id having "<<len<<"node! \n";
			return;
		}
		SingleNode *temp = new SingleNode();
		temp->data = data;
		temp->next = nullptr;
		if (pos == 1) {
			temp->next = root;
			root = temp;
		} else {
			SingleNode *p = root;
			for(int i=0; i<pos-2; i++) {
				p = p->next;
			}
			temp->next = p->next;
			p->next = temp;
		}
	}

	int findKthFromLast(int pos) {
		// 1st method: calculate length and move p to (len+1)-pos
		// int len = length();
		// int posToFind = (len+1)-pos;
		// SingleNode *p = root;
		// for(int i=0; i<posToFind-1; i++) {
		// 	p = p->next;
		// }
		// return p->data;

		// 2nd Method: move p2 by no of pos, and move p2 and p1 by 1 every time until end of list,
		// p1 will give desired element from last
		// 10 20 30 40 50
		SingleNode *p1, *p2;
		p1 = p2 = root;
		for(int i=0; i<pos-1; i++) {
			p2 = p2->next;
		}
		while(p2->next) {
			p2 = p2->next;
			p1 = p1->next;
		}
		return p1->data;
	}


	void erase(int pos) {
		int len = length();
		if(pos > len) {
			std::cout<<"Invalid location! \n";
			std::cout<<"Currently list contains "<<len<<" nodes! \n";
		} else if(pos == 1) {
			SingleNode *temp = root;
			root = temp->next;
			temp->next = nullptr;
			delete temp;
		} else {
			SingleNode *temp1 = root;
			for(int i = 0; i < pos-2; i++) {
				temp1 = temp1->next;
			}
			SingleNode *temp2 = temp1->next;
			temp1->next = temp2->next;
			temp2->next = nullptr;
			delete temp2;
		}
	}

	int length() {
		int count = 0;
		SingleNode *p;
		p = root;

		while(p) {
			count++;
			p = p->next;
		}
		return count;
	}

	void traverse() {
		SingleNode *p;
		p = root;

		if(p == nullptr){
			std::cout<<"No node in the list! \n";
		} else {
			while(p) {
				std::cout<<p->data<<"->";
				p = p->next;
			}
		}
	}

	void swap(int pos) {
		int len = length();
		if (pos > len-1) {
			std::cout<<"Swapping not possible! \n";
		} else {
			SingleNode *temp1, *temp2, *temp3;
			temp1 = root;
			for(int i=0; i<pos-1; i++) {
				temp1 = temp1->next;
			}
			temp2 = temp1->next;
			temp3 = temp2->next;

			temp2->next = temp3->next;
			temp3->next = temp2;
			temp1->next = temp3;
		}
	}

	void reverse() {
		SingleNode *curr, *prev, *next;
		curr = root;
		prev = nullptr;
		while (curr != nullptr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		root = prev;
	}

	void operation() {
		int ch;
		while(1) {

			std::cout<<"1. Push back \n";
			std::cout<<"2. Push front \n";
			std::cout<<"3. Pop back \n";
			std::cout<<"4. Pop front \n";
			std::cout<<"5. Insert \n";
			std::cout<<"6. Display \n";
			std::cout<<"7. Length \n";
			std::cout<<"8. Delete \n";
			std::cout<<"9. Find from back \n";
			std::cout<<"0. Exit \n\n";

			std::cout<<"Enter ur choice \n";
			std::cin>>ch;

			int data, pos;
			switch(ch) {
				case 1:
					std::cout<<"Enter data: \n";
					std::cin>>data;
					// pushBack(data);
					break;
				case 2:
					std::cout<<"Enter data: \n";
					std::cin>>data;
					pushFront(data);
					break;
				case 3:
					// popBack();
					break;
				case 4:
					popFront();
					break;
				case 5:
					std::cout<<"Enter position and data: \n";
					std::cin>>pos>>data;
					insert(pos, data);
					break;
				case 6:
					traverse();
					std::cout<<"\n";
					break;
				case 7:
					std::cout<<"List contains "<<length()<<"nodes! \n";
					break;
				case 8:
					std::cout<<"Enter position to delete: \n";
					std::cin>>pos;
					erase(pos);
					break;
				case 9:
					std::cout<<"Enter position to find from back: \n";
					std::cin>>pos;
					std::cout<<"data: "<<findKthFromLast(pos)<<"\n";
					break;
				case 0:
					exit(1);
				default:
					std::cout<<"Invalid choice!!!! \n";
					break;
			}
		}
	}
};


int main() {
	LinkedList l;
	l.operation();
	return 0;
}



