cmake_minimum_required(VERSION 3.14)
project(GTCV)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find pybind11
find_package(pybind11 REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/lib)

# Add the library
add_library(GTCV_lib STATIC 
    lib/src/gtcv.cpp
    lib/src/gtcv_signal.cpp
    lib/src/gtcv_signal.h
    lib/src/gtcv_objects.h
)

# Add the executable
add_executable(GTCV_exe lib/src/main.cpp)
target_link_libraries(GTCV_exe PRIVATE GTCV_lib)

# Add the Python bindings
pybind11_add_module(gtcv_python lib/python_bindings/bindings.cpp)
target_link_libraries(gtcv_python PRIVATE GTCV_lib)
