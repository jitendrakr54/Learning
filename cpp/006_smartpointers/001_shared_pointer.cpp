#include <iostream>
#include <memory> // for std::unique_ptr
 
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
    void print() { std::cout<< "Print resource\n"; }
};

void fun(std::unique_ptr<Resource> res) {
    res->print();
}

int main()
{
	// allocate a Resource object and have it owned by std::unique_ptr
	std::unique_ptr<Resource> res{ new Resource() };
    // fun(res); // not allowed since copy is disabled in unique_ptr
    fun(std::move(res));
    res->print();
    std::unique_ptr<int> res1{std::make_unique<int>()};
	return 0;
}