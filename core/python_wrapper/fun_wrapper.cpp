#include"fun.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;



PYBIND11_MODULE(cmake_example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function that adds two numbers");
    m.def("sayHi", &sayHi, "say hi");
    m.def("hi", [](int i,int j) {return i + j;}, "xxx");
}
