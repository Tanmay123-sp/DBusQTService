cmake_minimum_required(VERSION 3.16)

project(dbusService LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core DBus)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core DBus Widgets)

add_executable(dbusService
  main.cpp
  dbusservice.h dbusservice.cpp
)
target_link_libraries(dbusService Qt${QT_VERSION_MAJOR}::Core Qt6::DBus  Qt6::Widgets)

include(GNUInstallDirs)
install(TARGETS dbusService
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
