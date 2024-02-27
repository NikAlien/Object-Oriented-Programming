cmake_minimum_required(VERSION 3.24)
project(t1_NikAlien_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t1_NikAlien_1
        main.cpp Domain/Protein.cpp Domain/Protein.h Repo/Repo.cpp Repo/Repo.h Service/Serv.cpp Service/Serv.h UI/UI.cpp UI/UI.h)
