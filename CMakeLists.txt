PROJECT (MTOC++)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CMAKE_CXX_FLAGS "-Wall")
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
SET(MTOC++_VERSION_MAJOR 1)
SET(MTOC++_VERSION_MINOR 0)
ENABLE_TESTING()

CONFIGURE_FILE(
  "${PROJECT_SOURCE_DIR}/test/test.sh.in"
  "${PROJECT_BINARY_DIR}/test.sh"
  @ONLY
  )

CONFIGURE_FILE(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )


INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}")

FIND_PACKAGE(Ragel REQUIRED)
FIND_PACKAGE(Doxygen)
RAGEL_PARSER(mfilescanner)
RAGEL_PARSER(confscanner)
RAGEL_PARSER(postprocess)

ADD_EXECUTABLE(mtocpp mtocpp.cc mfilescanner.cc confscanner.cc)
ADD_EXECUTABLE(postprocess postprocess.cc)

INSTALL(TARGETS mtocpp postprocess DESTINATION bin)
INSTALL(FILES License.txt test/doxygen.m DESTINATION share/doc/mtocpp)

ADD_TEST(MTOCPP_TEST "${PROJECT_BINARY_DIR}/test.sh")
SET_TESTS_PROPERTIES(MTOCPP_TEST
  PROPERTIES FAIL_REGULAR_EXPRESSION "(failed)")

IF(DOXYGEN_FOUND)
  ADD_TEST(NAME MTOCPP_DOXYTEST COMMAND ${DOXYGEN_EXECUTABLE} "${PROJECT_SOURCE_DIR}/test/Doxyfile")
ENDIF(DOXYGEN_FOUND)

ADD_EXECUTABLE(accesstest access.cc mfilescanner.cc confscanner.cc)

# enable dashboard scripting
INCLUDE (CTest)

SET (CTEST_PROJECT_NAME "MTOC++")

# build a CPack driven installer package
SET (CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
SET (CPACK_PACKAGE_VERSION_MAJOR "${MTOC++_VERSION_MAJOR}")
SET (CPACK_PACKAGE_VERSION_MINOR "${MTOC++_VERSION_MINOR}")
SET (CPACK_PACKAGE_CONTACT "Martin Drohmann <mdrohmann@uni-muenster.de>")
SET (CPACK_PACKAGE_DESCRIPTION_SUMMARY "Doxygen filter for Matlab M-files and scripts")
SET (CPACK_PACKAGE_DESCRIPTION
  "This package includes two programs to build beautiful Doxygen documentation
  for Matlab projects. The filter program 'mtocpp' transforms relevant parts of
  the M-Files into C++ syntax, which can be parsed by doxygen. The generated
  html files can be processed by the program 'postprocess' in order to generate
  documentation looking more like Matlab.")
SET (CPACK_DEBIAN_PACKAGE_SECTION "devel")
SET (CPACK_DEBIAN_PACKAGE_SUGGESTS "doxygen")

INCLUDE (CPack)

