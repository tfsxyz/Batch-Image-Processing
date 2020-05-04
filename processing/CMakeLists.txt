project( processing_test )
cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

#打开全局moc
set(CMAKE_AUTOMOC ON)
#打开全局uic
set(CMAKE_AUTOUIC ON)
#打开全局rcc，本示例中没有使用qrc，此句可以去掉
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED Widgets)

find_package( OpenCV REQUIRED )

AUX_SOURCE_DIRECTORY(. DIR_SRCS)




ADD_EXECUTABLE(processing_test ${DIR_SRCS} ${RESOURCES} )
# ADD_EXECUTABLE(main main.cpp mainwindow.h mainwindow.cpp mainwindow.ui dialog.cpp dialog.h mainwindow.cpp mainwindow.h mainwindow.ui form.cpp form.h form.ui)
target_link_libraries( processing_test ${OpenCV_LIBS} )
target_link_libraries(processing_test Qt5::Widgets)

# AUX_SOURCE_DIRECTORY(. DIR_TEST)
# AUX_SOURCE_DIRECTORY(./processing DIR_TEST)
# ADD_EXECUTABLE(processing_test ${DIR_TEST} ./processing/processing_test.cpp)
# #  ADD_EXECUTABLE(main main.cpp mainwindow.h mainwindow.cpp mainwindow.ui dialog.cpp dialog.h mainwindow.cpp mainwindow.h mainwindow.ui form.cpp form.h form.ui)
# target_link_libraries( processing_test ${OpenCV_LIBS} )
# target_link_libraries(processing_test Qt5::Widgets)