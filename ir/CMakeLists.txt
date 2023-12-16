add_executable(run_flatc_exe ./src/main.cpp)
target_link_libraries(run_flatc_exe PRIVATE flatbuffers)
target_include_directories(run_flatc_exe PRIVATE "../core/include")
