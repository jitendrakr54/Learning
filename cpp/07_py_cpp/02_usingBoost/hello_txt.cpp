// https://shocksolution.com/python-basics-tutorials-and-examples/linking-python-and-c-with-boostpython/

#include <iostream>
#include <boost/python.hpp>

std::string fun() {
    std::string str;
    std::cout<<"Enter something: ";
    std::cin>>str;
    return str;
}

BOOST_PYTHON_MODULE(hello_txt) {
    boost::python::def("fun", fun);
}