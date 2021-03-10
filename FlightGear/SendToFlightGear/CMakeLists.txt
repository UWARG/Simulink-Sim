cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

FIND_PACKAGE( Boost 1.40 COMPONENTS REQUIRED system)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_definitions(-Wall -Wextra -g)

set(CMAKE_CXX_STANDARD 11)


add_executable(SendToFG main.cpp)
target_link_libraries(SendToFG LINK_PUBLIC ${Boost_LIBRARIES})
