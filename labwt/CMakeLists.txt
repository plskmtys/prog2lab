#
cmake_minimum_required(VERSION 2.8)
#
SET(WT_PROJECT_TARGET ladaapp.wt)

SET(WT_PROJECT_SOURCES
ladaapp.cpp
ladawidget.cpp
ladak.cpp
tortadiagram.cpp
)

set (CMAKE_CXX_FLAGS "-Wall -pedantic -DBOOST_SIGNALS_NO_DEPRECATION_WARNING")
SET (WT_CONNECTOR "wthttp" CACHE STRING "Connector used (wthttp)")
INCLUDE_DIRECTORIES(/usr/local/include)

ADD_EXECUTABLE(${WT_PROJECT_TARGET} ${WT_PROJECT_SOURCES})
TARGET_LINK_LIBRARIES(${WT_PROJECT_TARGET} ${WT_CONNECTOR} wt boost_signals)

find_package(Doxygen)
if(DOXYGEN_FOUND)
add_custom_target(doc
${DOXYGEN_EXECUTABLE} Doxyfile
COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)
