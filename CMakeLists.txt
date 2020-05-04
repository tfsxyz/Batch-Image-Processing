project( main )
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
set(RESOURCES 
./Widget/ico/left.qrc
)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)
AUX_SOURCE_DIRECTORY(./Widget DIR_SRCS)
AUX_SOURCE_DIRECTORY(./Widget/ico DIR_SRCS)
AUX_SOURCE_DIRECTORY(./processing DIR_SRCS)
# AUX_SOURCE_DIRECTORY(./processing/processing.cpp DIR_SRCS)
# AUX_SOURCE_DIRECTORY(./processing/processing.hpp DIR_SRCS)

ADD_EXECUTABLE(main ${DIR_SRCS} ${RESOURCES} ./main.cpp)
# ADD_EXECUTABLE(main main.cpp mainwindow.h mainwindow.cpp mainwindow.ui dialog.cpp dialog.h mainwindow.cpp mainwindow.h mainwindow.ui form.cpp form.h form.ui)
target_link_libraries( main ${OpenCV_LIBS} )
target_link_libraries(main Qt5::Widgets)

# AUX_SOURCE_DIRECTORY(. DIR_TEST)
# AUX_SOURCE_DIRECTORY(./processing DIR_TEST)
# ADD_EXECUTABLE(processing_test ${DIR_TEST} ./processing/processing_test.cpp)
# #  ADD_EXECUTABLE(main main.cpp mainwindow.h mainwindow.cpp mainwindow.ui dialog.cpp dialog.h mainwindow.cpp mainwindow.h mainwindow.ui form.cpp form.h form.ui)
# target_link_libraries( processing_test ${OpenCV_LIBS} )
# target_link_libraries(processing_test Qt5::Widgets)