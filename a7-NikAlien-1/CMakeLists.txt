cmake_minimum_required(VERSION 3.24)
project(a7_NikAlien_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Domain)
include_directories(Repository)
include_directories(Service)
include_directories(Tests)
include_directories(UI)

add_executable(a7_NikAlien_1
        Domain/Dog.cpp
        Domain/Dog.h
        Repository/Repo.cpp
        Repository/Repo.h
        Service/Service.cpp
        Service/Service.h
        UI/UIAdmin.cpp
        UI/UIAdmin.h
        UI/UIMain.cpp
        UI/UIMain.h
        UI/UIUser.cpp
        UI/UIUser.h
        main.cpp Repository/FileAdoptList.cpp Repository/FileAdoptList.h Repository/CSVAdoptList.cpp Repository/CSVAdoptList.h Repository/HTMLAdoptList.cpp Repository/HTMLAdoptList.h Domain/DogValidator.cpp Domain/DogValidator.h Repository/RepoException.cpp Repository/RepoException.h)
