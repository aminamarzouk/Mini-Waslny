cmake_minimum_required(VERSION 3.22)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

include_directories(DataStructure)

add_executable(data_structure
        DataStructure/Edge.cpp
        DataStructure/Edge.h
        DataStructure/Graph.cpp
        DataStructure/Graph.h
        DataStructure/Source.cpp
        DataStructure/Vertex.cpp
        DataStructure/Vertex.h)
