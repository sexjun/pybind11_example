pybind11_add_module(cpp_py_example fun_wrapper.cpp)
target_include_directories(cpp_py_example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_link_libraries(cpp_py_example PUBLIC none_lib)


pybind11_add_module(obj_wrapper obj_wrapper.cpp)
target_include_directories(obj_wrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_link_libraries(obj_wrapper PUBLIC none_lib)
