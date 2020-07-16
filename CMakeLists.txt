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


find_package(Qt5 COMPONENTS
    Widgets
    SerialPort
    WebEngineWidgets
    REQUIRED)


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

  src/welcome/welcome.h
  src/welcome/welcome.html


  src/dock/ads_globals.cpp
  src/dock/DockAreaTabBar.cpp
  src/dock/DockAreaTitleBar.cpp
  src/dock/DockAreaWidget.cpp
  src/dock/DockContainerWidget.cpp
  src/dock/DockManager.cpp
  src/dock/DockOverlay.cpp
  src/dock/DockSplitter.cpp
  src/dock/DockWidget.cpp
  src/dock/DockWidgetTab.cpp
  src/dock/DockingStateReader.cpp
  src/dock/DockFocusController.cpp
  src/dock/ElidingLabel.cpp
  src/dock/FloatingDockContainer.cpp
  src/dock/FloatingDragPreview.cpp
  src/dock/IconProvider.cpp
  src/dock/DockComponentsFactory.cpp
  src/dock/ads.qrc

  src/dock/ads_globals.h
  src/dock/DockAreaTabBar.h
  src/dock/DockAreaTitleBar.h
  src/dock/DockAreaTitleBar_p.h
  src/dock/DockAreaWidget.h
  src/dock/DockContainerWidget.h
  src/dock/DockManager.h
  src/dock/DockOverlay.h
  src/dock/DockSplitter.h
  src/dock/DockWidget.h
  src/dock/DockWidgetTab.h
  src/dock/DockingStateReader.h
  src/dock/DockFocusController.h
  src/dock/ElidingLabel.h
  src/dock/FloatingDockContainer.h
  src/dock/FloatingDragPreview.h
  src/dock/IconProvider.h
  src/dock/DockComponentsFactory.h

  src/dock/linux/FloatingWidgetTitleBar.cpp
  src/dock/linux/FloatingWidgetTitleBar.h
)

target_link_libraries(skui PRIVATE
    Qt5::Widgets
    Qt5::SerialPort
    Qt5::WebEngineWidgets
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "bin" COMPONENT application)

