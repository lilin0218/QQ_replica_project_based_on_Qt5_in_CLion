cmake_minimum_required(VERSION 3.31)
project(Heart LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt 安装路径
set(CMAKE_PREFIX_PATH "D:/APP/QT5/5.15.2/mingw81_64")

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Network Sql Charts)

set(SOURCES
        main.cpp
        appconfig.cpp
        databasemanager.cpp
        protocol.cpp
        loginpage.cpp
        poolmanager.cpp
        mainpage.cpp
        chatpage.cpp
        dynamicgradientbg.cpp
        createpage.cpp
        addpage.cpp
        MyServer.cpp
        MyClient.cpp
        ChatManager.cpp
        DeveloperPage.cpp
)

set(HEADERS
        appconfig.h
        databasemanager.h
        protocol.h
        loginpage.h
        poolmanager.h
        mainpage.h
        chatpage.h
        dynamicgradientbg.h
        createpage.h
        addpage.h
        MyServer.h
        MyClient.h
        ChatManager.h
        DeveloperPage.h
)

set(UI_FILES
        loginpage.ui
        mainpage.ui
        chatpage.ui
        createpage.ui
        addpage.ui
        DeveloperPage.ui
)

set(RESOURCES
        res.qrc
)

add_executable(${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
        ${UI_FILES}
        ${RESOURCES}
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network Qt5::Sql Qt5::Charts
)

# 复制 Qt DLL
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX "")
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif()

    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
    endif()

    # 平台插件
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/"
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/"
        )
    endif()

    # Qt 核心 DLL
    foreach(QT_LIB Core Gui Widgets Charts Network Sql)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
        )
    endforeach()
endif()
