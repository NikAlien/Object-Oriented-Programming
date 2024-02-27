cmake_minimum_required(VERSION 3.24)
project(t2_NikAlien_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(t2_NikAlien_1
        main.cpp UI.cpp UI.h Service.cpp Service.h Car.cpp Car.h Engine/Engine.cpp Engine/Engine.h Engine/Electric.cpp Engine/Electric.h Engine/Turbo.cpp Engine/Turbo.h)
