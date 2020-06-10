cmake_minimum_required(VERSION 3.5)

project(skui
    VERSION 0.6
    LANGUAGES CXX
    DESCRIPTION "A open source serial interface"
    )

include(CPack)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Cpack stuff
set(CPACK_PACKAGE_NAME "Skui")
set(CPACK_PACKAGE_DESCRIPTION "A open source serial interface")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "CPACK_PACKAGE_DESCRIPTION_SUMMARY")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://kalbra.github.io/skui/")


find_package(Qt5 COMPONENTS Widgets SerialPort REQUIRED)


add_executable(skui
  src/main.cpp

  src/core/mainwindow.cpp
  src/core/mainwindow.h
  src/core/mainwindow.ui

  src/boardeditor/boardeditor.cpp
  src/boardeditor/boardeditor.h

  src/boardeditor/dialog/adddialog.cpp
  src/boardeditor/dialog/adddialog.h
  src/boardeditor/dialog/adddialog.ui

  src/core/board.cpp
  src/core/board.h

  src/valuedecoder/valuedecoder.cpp
  src/valuedecoder/valuedecoder.h

  src/fileio/fileio.h
  src/fileio/fileio.cpp

  src/serialio/serialio.h
  src/serialio/serialio.cpp

  src/saveengine/saveengine.cpp
  src/saveengine/saveengine.h

  src/toolbar/toolbar.cpp
  src/toolbar/toolbar.h

  src/fileio/filedialog.h

  src/filenameengine/filenameengine.h

  src/boardelements/boardelements.h
)

target_link_libraries(skui PRIVATE
    Qt5::Widgets
    Qt5::SerialPort
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "bin" COMPONENT application)

