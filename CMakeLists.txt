cmake_minimum_required(VERSION 4.0)
project(programmazione)

set(CMAKE_CXX_STANDARD 17)

add_executable(programmazione main.cpp
        AbstractAccount.cpp
        AbstractAccount.h
        Product.h
        Product.cpp
        Inventory.cpp
        Inventory.h
        AbstractFactory.h
        AbstractFactory.cpp
        Application.h
        Application.cpp)
