PROJECT (MTOC++)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CMAKE_CXX_FLAGS "-Wall")
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

FIND_PACKAGE(Ragel REQUIRED)
RAGEL_PARSER(mfilescanner)
RAGEL_PARSER(confscanner)
RAGEL_PARSER(postprocess)

add_executable(mtoc mtoc.cc mfilescanner.cc confscanner.cc)
add_executable(postprocess postprocess.cc)

add_executable(accesstest access.cc mfilescanner.cc confscanner.cc)
