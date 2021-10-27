cmake_minimum_required(VERSION 3.2.1 FATAL_ERROR)

SET(CMAKE_C_COMPILER g++)
add_definitions(-std=c++14)

set(Torch_DIR ${PROJECT_SOURCE_DIR}/../../libtorch/share/cmake/Torch)

find_package(Torch REQUIRED)

# opencv
find_package(OpenCV REQUIRED)

# include headers
include_directories(${OpenCV_INCLUDE_DIRS} ${TORCH_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/../include)

link_directories("${PROJECT_SOURCE_DIR}/../lib")

aux_source_directory(${PROJECT_SOURCE_DIR}/torch_cpp_test/ test_src)

add_executable( torch_cpp_test ${test_src} )

target_link_libraries(torch_cpp_test libalgimg.a)

target_link_libraries(torch_cpp_test ${OpenCV_LIBS})

target_link_libraries(torch_cpp_test ${TORCH_LIBRARIES})



