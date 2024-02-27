cmake_minimum_required(VERSION 3.24)
project(a45_NikAlien)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a45_NikAlien
        Domain/Dog.cpp
        Domain/Dog.h
        main.cpp Repository/DynamicArray.h Repository/Repo.h Repository/Repo.cpp Service/Service.h Service/Service.cpp UI/UIMain.cpp UI/UIMain.h UI/UIAdmin.cpp UI/UIAdmin.h UI/UIUser.cpp UI/UIUser.h Tests/test.cpp Tests/test.h Domain/Dog.h Domain/Dog.cpp)
