cmake_minimum_required(VERSION 3.6)
project(py11_t VERSION 0.1.0 LANGUAGES C CXX)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.11.1
    )
FetchContent_MakeAvailable(pybind11)
set(PYBIND11_PYTHON_VERSION "3.10·")

add_subdirectory(core)
