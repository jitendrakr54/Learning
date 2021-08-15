#include "ToyFactory.h"

namespace design_pattern {
namespace fdp {

Toy* ToyFactory::createToy(int type) {
	Toy *toy = nullptr;
	switch(type) {
		case 1:
			toy = new Car;
			break;
		case 2:
			toy = new Bike;
			break;
		case 3:
			toy = new Plane;
			break;
		default:
			toy = nullptr;
			break;
	}
    toy->prepareParts();
    toy->combineParts();
    toy->assembleParts();
    toy->applyLabel();
	return toy;
}

}
}