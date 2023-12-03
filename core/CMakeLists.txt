cmake_minimum_required(VERSION 3.6)

add_executable(exeAble src/main.cpp src/fun.cpp)
target_include_directories(exeAble PUBLIC include)

add_library(none_lib SHARED src/fun.cpp)
target_include_directories(none_lib PUBLIC include)

pybind11_add_module(cmake_example python_wrapper/fun_wrapper.cpp)
target_include_directories(cmake_example PUBLIC include)
target_link_libraries(cmake_example PUBLIC none_lib)
