cmake_minimum_required(VERSION 3.5)

project(Dsba2022 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        attributes.h
        secondwindow.h
        secondwindow.cpp
        secondwindow.ui
        helpwindow.h
        helpwindow.cpp
        helpwindow.ui
        authorinfo.h
        authorinfo.cpp
        authorinfo.ui
        addwindow.h
        addwindow.cpp
        addwindow.ui
        additionalwindow.h
        additionalwindow.cpp
        additionalwindow.ui
        speakerwindow.h
        speakerwindow.cpp
        speakerwindow.ui
        speaker.h
        videowindow.h
        videowindow.cpp
        videowindow.ui
        video.h
        filterwindow.h
        filterwindow.cpp
        filterwindow.ui
        filters.h
        talkswindow.h
        talkswindow.cpp
        talkswindow.ui
        GlobalVariables.h
        projectinfo.h
        projectinfo.cpp
        projectinfo.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Dsba2022
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Dsba2022 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Dsba2022 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Dsba2022
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Dsba2022 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Dsba2022 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Dsba2022)
endif()
