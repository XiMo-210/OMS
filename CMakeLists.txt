cmake_minimum_required(VERSION 3.24)
project(OMS)

set(CMAKE_CXX_STANDARD 17)

add_executable(OMS src/main.cpp include/user.h include/admin.h include/company.h include/list.h include/order.h include/menu.h src/menu.cpp include/file.h src/admin.cpp include/companyList.h include/orderList.h include/listNode.h src/order.cpp src/company.cpp src/orderList.cpp src/companyList.cpp src/user.cpp src/user.cpp)
