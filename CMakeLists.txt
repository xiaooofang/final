cmake_minimum_required(VERSION 3.5)
project(NetScope LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network)

target_link_libraries(EXfinal
    Qt6::Widgets
    Qt6::Network
)


add_executable(NetScope
    main.cpp
    mainwindow.h mainwindow.cpp
    widgets/imagewidget.h widgets/imagewidget.cpp
    widgets/gamewidget.h widgets/gamewidget.cpp
    widgets/chatwidget.h widgets/chatwidget.cpp
)

target_link_libraries(NetScope
    Qt6::Widgets
    Qt6::Network
)
