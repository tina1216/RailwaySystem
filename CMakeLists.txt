cmake_minimum_required(VERSION 3.23)
project(ClassNote)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClassNote main.cpp TicketNode.h SubwayNode.h SubwayList.h SubwayList.cpp CustomerNode.h CustomerList.h Utils.cpp Utils.h TicketList.h Admin.h Admin.cpp TicketList.cpp CustomerList.cpp)
