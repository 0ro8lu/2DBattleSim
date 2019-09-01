cmake_minimum_required(VERSION 2.7)
project(2DBattleSim)

# Set C++ version to 14
set(CMAKE_CXX_STANDARD 14)

# Source dirs
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Include dirs
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} ncurses)
