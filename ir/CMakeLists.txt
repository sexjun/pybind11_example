add_executable(flatc_exe ./src/main.cpp)
target_link_libraries(flatc_exe PRIVATE flatbuffers)
