pybind11_add_module(cmake_example fun_wrapper.cpp)
target_include_directories(cmake_example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_link_libraries(cmake_example PUBLIC none_lib)
