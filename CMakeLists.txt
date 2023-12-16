cmake_minimum_required(VERSION 3.6)
project(py11_t VERSION 0.1.0 LANGUAGES C CXX)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

include(CPack)

include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.11.1
    )
FetchContent_MakeAvailable(pybind11)
set(PYBIND11_PYTHON_VERSION "3.10·")


FetchContent_Declare(
    flatbuffers
    GIT_REPOSITORY https://github.com/google/flatbuffers.git
    GIT_TAG v23.5.26
)
# set(FLATBUFFERS_CXX_FLAGS, "-Wno-error")
FetchContent_MakeAvailable(flatbuffers)

set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(core)


add_subdirectory(ir)
