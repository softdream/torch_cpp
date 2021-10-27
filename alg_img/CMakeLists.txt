cmake_minimum_required(VERSION 3.2.1 FATAL_ERROR)
project(detector) 
 
SET(CMAKE_C_COMPILER g++)
add_definitions(-std=c++14) 
 

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")

# libTorch
#set(Torch_DIR /home/ddf/Test/java_torch_project/libtorch/share/cmake/Torch)

set(Torch_DIR ${PROJECT_SOURCE_DIR}/../libtorch/share/cmake/Torch)

find_package(Torch REQUIRED)

# opencv
find_package(OpenCV REQUIRED)
 
# include headers
include_directories(${OpenCV_INCLUDE_DIRS} ${TORCH_INCLUDE_DIRS})
 
include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src source)

#add_executable(algimg ${source})

# generate static and dynamic libs
add_library(algimg SHARED ${source})

add_library(algimg_static STATIC ${source})

target_link_libraries(algimg ${TORCH_LIBRARIES})

target_link_libraries(algimg ${OpenCV_LIBS})

target_link_libraries(algimg_static ${TORCH_LIBRARIES})
target_link_libraries(algimg_static ${OpenCV_LIBS})

set_property(TARGET algimg PROPERTY CXX_STANDARD 14)

set_property(TARGET algimg_static PROPERTY CXX_STANDARD 14)

set_target_properties(algimg_static PROPERTIES OUTPUT_NAME "algimg")

