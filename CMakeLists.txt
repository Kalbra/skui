cmake_minimum_required(VERSION 3.5)

project(skui LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()


find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(skui SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
  add_executable(skui
    src/main.cpp

    src/core/mainwindow.cpp
    src/core/mainwindow.h
    src/core/mainwindow.ui

    src/core/board.cpp
    src/core/board.h

    src/fileio/fileio.h
    src/fileio/fileio.cpp

    src/filebar/filebar.cpp
    src/filebar/filebar.h

    src/saveengine/saveengine.cpp
    src/saveengine/saveengine.h

    src/fileio/filedialog.h

    src/filenameengine/filenameengine.h

    src/settings/settingstruct.h

    src/boardelements/boardelements.h
  )
endif()

target_link_libraries(skui PRIVATE Qt5::Widgets)
