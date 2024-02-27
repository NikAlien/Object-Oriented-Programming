cmake_minimum_required(VERSION 3.24)
project(A89_Qt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt/6.4.3_3/lib/cmake")

include_directories(Domain)
include_directories(Repository)
include_directories(Service)
include_directories(GUI)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(A89_Qt main.cpp Domain/DogValidator.h Domain/DogValidator.cpp
        Domain/Dog.h Domain/Dog.cpp Repository/Repo.h Repository/Repo.cpp
        Repository/HTMLAdoptList.h Repository/HTMLAdoptList.cpp
        Repository/FileAdoptList.h Repository/FileAdoptList.cpp
        Repository/CSVAdoptList.h Repository/CSVAdoptList.cpp
        Repository/RepoException.h Repository/RepoException.cpp Service/Service.h Service/Service.cpp
        GUI/WelcomeGUI.h GUI/WelcomeGUI.cpp
        GUI/UserGUI.h GUI/UserGUI.cpp GUI/MainGUI.cpp GUI/MainGUI.h GUI/AdminGUI.cpp GUI/AdminGUI.h GUI/SlideShow.cpp GUI/SlideShow.h)

target_link_libraries(A89_Qt
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

