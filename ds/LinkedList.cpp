#include <iostream>

struct Node {
    int data;
    struct Node* link;
};

class LinkedList {
    private:
        Node* root;
    public:
        LinkedList() : root{nullptr} {}
        void pushFront(int data) {
            Node *temp = new Node();
            temp->data = data;
            temp->link = nullptr;
            if(root == nullptr) {
                root = temp;
            } else {
                temp->link = root;
                root = temp;
            }
        }

        void popFront() {
            if(root == nullptr) {
                return;
            } else {
                Node* temp = root;
                root = temp->link;
                temp->link = nullptr;
                delete temp;
            }
        }

        void insert(int pos, int data) {
            Node* temp = new Node;
            temp->data = data;
            temp->link = nullptr;
            if(pos == 1) {
                temp->link = root;
                root = temp;
            } else {
                Node *p = root;
                for(int i=0; i<pos-2; ++i) {
                    p = p->link;
                }
                temp->link = p->link;
                p->link = temp;
            }
        }

        void erase(int pos) {
            Node *temp = root;
            if(pos == 1) {
                root = temp->link;
                temp->link = nullptr;
                delete temp;
            } else {
                Node *p = root;
                for(int i=0; i<pos-2; ++i) {
                    p = p->link;
                }
                temp = p->link;
                p->link = temp->link;
                temp->link = nullptr;
                delete temp;
            }
        }

        void reverse() {
            Node *curr, *prev, *next;
            prev = next = nullptr;
            curr = root;
            while(curr != nullptr) {
                next = curr->link;
                curr->link = prev;
                prev = curr;
                curr = next;
            }
            root = prev;
        }

        void traverse() {
            if(root == nullptr) {
                return;
            }
            Node *temp = root;
            while(temp) {
                std::cout<<temp->data<<" ";
                temp = temp->link;
            }
            std::cout<<"\n";
        }
};