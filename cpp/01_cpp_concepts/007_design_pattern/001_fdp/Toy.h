// #pragma once

#include <iostream>

namespace design_pattern {
namespace fdp {

class Toy {
private:
	std::string m_name;
	float m_price;
public:
	Toy(std::string name, float price) : m_name(name), m_price(price) {}
	virtual void prepareParts() = 0;
	virtual void combineParts() = 0;
	virtual void assembleParts() = 0;
	virtual void applyLabel() = 0;
	virtual void showProducts() = 0;
	std::string getName() { return m_name; }
	float getPrice() { return m_price; }
};

class Car : public Toy {
public:
	Car() : Toy("Maruti", 100) {}
	void prepareParts() { std::cout<< "Preparing Car parts!\n"; }
	void combineParts() { std::cout<< "Combining Car parts!\n"; }
	void assembleParts() { std::cout<< "assembling Car parts!\n"; }
	void applyLabel() { std::cout<< "applying Car label!\n"; }
	void showProducts() { std::cout<<"Car: "<<getName()<<" Price: "<<getPrice()<<"\n"; }
};

class Bike : public Toy {
public:
	Bike() : Toy("TVS", 50) {}
	void prepareParts() { std::cout<< "Preparing Bike parts!\n"; }
	void combineParts() { std::cout<< "Combining Bike parts!\n"; }
	void assembleParts() { std::cout<< "assembling Bike parts!\n"; }
	void applyLabel() { std::cout<< "applying Bike label!\n"; }
	void showProducts() { std::cout<<"Bike: "<<getName()<<" Price: "<<getPrice()<<"\n"; }
};

class Plane : public Toy {
public:
	Plane() : Toy("Indigo", 500) {}
	void prepareParts() { std::cout<< "Preparing Plane parts!\n"; }
	void combineParts() { std::cout<< "Combining Plane parts!\n"; }
	void assembleParts() { std::cout<< "assembling Plane parts!\n"; }
	void applyLabel() { std::cout<< "applying Plane label!\n"; }
	void showProducts() { std::cout<<"Plane: "<<getName()<<" Price: "<<getPrice()<<"\n"; }
};

}
}
