#include <iostream>
#include "ToyFactory.h"

int main() {
    int type; //Factory design pattern
	design_pattern::fdp::Toy *t = nullptr;
	while(true) {
		std::cout<<"Enter toy type or zeor to exit: ";
		std::cin>>type;
		if(!type)
			break;
		t = design_pattern::fdp::ToyFactory::createToy(type);
		if(t) {
			t->showProducts();
//			delete t;
		}
	}
    return 0;
}