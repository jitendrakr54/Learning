// #pragma once

#include "Toy.h"

namespace design_pattern {
namespace fdp {
class ToyFactory {
public:
	static Toy* createToy(int choice);
};
}
}
