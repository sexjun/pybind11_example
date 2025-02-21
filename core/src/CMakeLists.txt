
add_executable(exeAble main.cpp fun.cpp fun.hpp)
target_include_directories(exeAble PUBLIC include)

add_library(none_lib SHARED main.cpp fun.cpp fun.hpp)
target_include_directories(none_lib PUBLIC include)
