PROJECT (MTOC++)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(MTOC++_VERSION_MAJOR 1)
SET(MTOC++_VERSION_MINOR 1)

# Default install prefix is "/usr/local"
SET(CUSTOM_DOC_DIR "share/doc/mtocpp"
  CACHE PATH "Custom directory where the documentation files will be installed")

SET(CMAKE_CXX_FLAGS "-Wall")
# path to FindRagel.cmake and WindowsToolChain.cmake
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# enable make test
ENABLE_TESTING()

# files that need configuration...
CONFIGURE_FILE(
  "${PROJECT_SOURCE_DIR}/test/test.sh.in"
  "${PROJECT_BINARY_DIR}/test.sh"
  @ONLY
  )

CONFIGURE_FILE(
  "${PROJECT_SOURCE_DIR}/src/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

CONFIGURE_FILE(
  "${PROJECT_SOURCE_DIR}/test/mtoc.sh.in"
  "${PROJECT_SOURCE_DIR}/test/mtoc.sh"
  )

CONFIGURE_FILE(
  "${PROJECT_SOURCE_DIR}/src/docs/doxygen.conf.in"
  "${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf"
  )

# pathes where to look for header files
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/src")

FIND_PACKAGE(Ragel REQUIRED)
FIND_PACKAGE(Doxygen REQUIRED)

# Ragel preprocessing
RAGEL_PARSER(src/mfilescanner)
RAGEL_PARSER(src/confscanner)
RAGEL_PARSER(src/postprocess)

# create mtocpp
ADD_EXECUTABLE(mtocpp src/mtocpp.cc mfilescanner.cc confscanner.cc)
# create mtocpp_post
ADD_EXECUTABLE(mtocpp_post postprocess.cc)

# add options for cross compilation on windows
IF(CMAKE_CROSSCOMPILING)
  TARGET_LINK_LIBRARIES(mtocpp -lshlwapi)
ENDIF(CMAKE_CROSSCOMPILING)

# add target for documentation
ADD_CUSTOM_TARGET(doxygen ALL
  COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf
  COMMAND ${PROJECT_BINARY_DIR}/mtocpp_post ${PROJECT_BINARY_DIR}/docs
  COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/src/docs/tabs.css ${PROJECT_BINARY_DIR}/docs
  COMMENT "Creating documentation... (see ${PROJECT_BINARY_DIR}/docs/doxygen.log for output)"
  DEPENDS mtocpp mtocpp_post
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/docs"
  )

INSTALL(TARGETS mtocpp mtocpp_post DESTINATION bin)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/License.txt DESTINATION ${CUSTOM_DOC_DIR})
#INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/mtocpp.conf.example DESTINATION ${CUSTOM_DOC_DIR})
INSTALL(DIRECTORY ${PROJECT_BINARY_DIR}/docs DESTINATION ${CUSTOM_DOC_DIR})

# add test target: test examples
ADD_TEST(MTOCPP_TEST "${PROJECT_BINARY_DIR}/test.sh")
SET_TESTS_PROPERTIES(MTOCPP_TEST
  PROPERTIES FAIL_REGULAR_EXPRESSION "(failed)")

ADD_TEST(NAME MTOCPP_DOXYTEST COMMAND ${DOXYGEN_EXECUTABLE} "${PROJECT_SOURCE_DIR}/test/doxygen.conf")
# enable dashboard scripting
INCLUDE (CTest)

SET (CTEST_PROJECT_NAME "MTOC++")

# build a CPack driven installer package
SET (CPACK_GENERATOR "DEB;TGZ")
SET (CPACK_SOURCE_GENERATOR "TGZ")
SET (CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
SET (CPACK_PACKAGE_VERSION_MAJOR "${MTOC++_VERSION_MAJOR}")
SET (CPACK_PACKAGE_VERSION_MINOR "${MTOC++_VERSION_MINOR}")
SET (CPACK_PACKAGE_VENDOR "MDDW")
SET (CPACK_PACKAGE_CONTACT "Martin Drohmann <mdrohmann@uni-muenster.de>, Daniel Wirtz <daniel.wirtz@mathematik.uni-stuttgart.de>")
SET (CPACK_PACKAGE_DESCRIPTION_SUMMARY "Doxygen filter for Matlab M-files and scripts")
SET (CPACK_PACKAGE_DESCRIPTION
  "This package includes two programs to build beautiful Doxygen documentation
  for Matlab projects. The filter program 'mtocpp' transforms relevant parts of
  the M-Files into C++ syntax, which can be parsed by doxygen. The generated
  html files can be processed by the program 'postprocess' in order to generate
  documentation looking more like Matlab.")
SET (CPACK_DEBIAN_PACKAGE_SECTION "devel")
SET (CPACK_DEBIAN_PACKAGE_SUGGESTS "doxygen")
SET (CPACK_SOURCE_IGNORE_FILES "/CVS/;/\\\\.svn/;\\\\.swp$;\\\\.git/;\\\\.gitignore;build/;")

INCLUDE (CPack)
