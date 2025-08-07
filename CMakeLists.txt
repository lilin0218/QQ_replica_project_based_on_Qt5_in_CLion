cmake_minimum_required(VERSION 3.31)
project(Heart)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/APP/QT5/5.15.2/mingw81_64")

find_package(Qt5 COMPONENTS
    Core
    Gui
    Widgets
    Network
    Sql
    Charts
    REQUIRED)

add_executable(Heart
    main.cpp
    appconfig.h appconfig.cpp
    databasemanager.h databasemanager.cpp
        protocol.h protocol.cpp
    loginpage.h loginpage.cpp loginpage.ui
    res.qrc
    poolmanager.h poolmanager.cpp
    mainpage.h mainpage.cpp mainpage.ui


    chatpage.h chatpage.cpp chatpage.ui
    dynamicgradientbg.h dynamicgradientbg.cpp
    createpage.h createpage.cpp createpage.ui
    addpage.h addpage.cpp addpage.ui
        MyServer.cpp
        MyServer.h
        MyClient.cpp
        MyClient.h
        ChatManager.cpp
        ChatManager.h
        DeveloperPage.cpp
        DeveloperPage.h
        DeveloperPage.ui

)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(Heart
    PRIVATE Qt5::Core
    PRIVATE Qt5::Gui
    PRIVATE Qt5::Widgets
    PRIVATE Qt5::Network
    PRIVATE Qt5::Sql
    PRIVATE Qt5::Charts
)

# DLL复制逻辑保持不变
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets Charts)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach ()
endif ()
