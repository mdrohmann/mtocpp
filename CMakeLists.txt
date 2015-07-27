cmake_minimum_required(VERSION 3.0)
project(MTOC++ LANGUAGES CXX VERSION 1.5)

# This is the default location for docs.
# Note that ${CMAKE_INSTALL_PREFIX} will be prepended automatically
# unless this is set to an absolute path.
if (NOT CUSTOM_DOC_DIR)
    set(CUSTOM_DOC_DIR "/share/doc/mtocpp"
      CACHE PATH "Custom directory where the documentation files will be installed")
endif()

set(CMAKE_CXX_FLAGS "-Wall")
# path to FindRagel.cmake and WindowsToolChain.cmake
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

FIND_PACKAGE(Ragel REQUIRED)
FIND_PACKAGE(Doxygen REQUIRED)
FIND_PACKAGE(LATEX QUIET)

IF(DOXYGEN_DOT_FOUND)
  SET(MTOC++_HAVE_DOT "YES")
ELSE()
  SET(MTOC++_HAVE_DOT "NO")
ENDIF()

# files that need configuration...
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/test/test.sh.in"
  "${CMAKE_CURRENT_BINARY_DIR}/test.sh"
  @ONLY
  )

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/src/config.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/config.h"
  )

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/test/mtoc.sh.in"
  "${CMAKE_CURRENT_SOURCE_DIR}/test/mtoc.sh"
  )

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/src/docs/doxygen.conf.in"
  "${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf"
  )

# pathes where to look for header files
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_BINARY_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Ragel preprocessing
RAGEL_PARSER(src/mfilescanner_parser)
RAGEL_PARSER(src/confscanner)
RAGEL_PARSER(src/postprocess)

# create mtocpp
ADD_EXECUTABLE(mtocpp src/mtocpp.cc mfilescanner_parser.cc src/mfilescanner.cc confscanner.cc)
# create mtocpp_post
ADD_EXECUTABLE(mtocpp_post postprocess.cc)

# add options for cross compilation on windows
IF(CMAKE_CROSSCOMPILING OR MINGW)
  TARGET_LINK_LIBRARIES(mtocpp -lshlwapi)
ENDIF()

# Get current date
string(TIMESTAMP CURRENT_DATE "%d-%m-%Y")

# add target for HTML documentation
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/docs/mainpage.c.in ${CMAKE_CURRENT_SOURCE_DIR}/src/docs/mainpage.c)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/docs/download_licenses.c.in ${CMAKE_CURRENT_SOURCE_DIR}/src/docs/download_licenses.c)
add_custom_target(documentation_html ALL
  COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf
  COMMAND mtocpp_post -q ${CMAKE_CURRENT_BINARY_DIR}/docs
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/src/docs/tabs.css ${CMAKE_CURRENT_BINARY_DIR}/docs/
  DEPENDS mtocpp mtocpp_post
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/docs"
  COMMENT "Creating HTML documentation... (see ${CMAKE_CURRENT_BINARY_DIR}/docs/doxygen.log for warnings)"
)

# add target for pdf documentation
if(LATEX_COMPILER)
    add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/latex/refman.pdf
      COMMAND make
      COMMENT "Creating PDF documentation... (see ${CMAKE_CURRENT_BINARY_DIR}/latex/refman.log for latex errors/warnings)"
      WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/latex/"
    )
    add_custom_target(documentation_pdf ALL
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/latex/refman.pdf ${CMAKE_CURRENT_BINARY_DIR}/docs/manual.pdf
      COMMAND ${CMAKE_COMMAND} -E echo "PDF docs at ${CMAKE_CURRENT_BINARY_DIR}/docs/manual.pdf!"
      #COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_BINARY_DIR}/docs/latex
      DEPENDS documentation_html ${CMAKE_CURRENT_BINARY_DIR}/latex/refman.pdf
    )
endif()

# Developer use only. Used to easily maintain the documentation website & tarballs.
if (EXISTS ${WS_SRC})
    find_package(Java REQUIRED)
    
    add_custom_target(create_sourcetar
        COMMAND ${CMAKE_COMMAND} -E tar "czf" 
            ${WS_SRC}/mtoc++_src_${MTOC++_VERSION}.tar.gz cmake/ src/ tools/ test/ CMakeLists.txt INSTALL LICENSE
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
    
    add_custom_target(create_win_binaries_packages
        COMMAND "${Java_JAR_EXECUTABLE}" cfM 
            ${WS_SRC}/mtoc++_win_${MTOC++_VERSION}.zip win32/ win64/ tools/ INSTALL LICENSE
        COMMAND "${Java_JAR_EXECUTABLE}" cfM
            ${WS_SRC}/mtoc++_win_binaries_${MTOC++_VERSION}.zip win32/ win64/ INSTALL LICENSE
        
        # MatLab FEX file 
        COMMAND "${Java_JAR_EXECUTABLE}" cfM
            mtoc++_fex_${MTOC++_VERSION}.zip cmake/ src/ tools/ test/ CMakeLists.txt INSTALL ${CMAKE_CURRENT_BINARY_DIR}/docs/manual.pdf
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
    add_custom_target(create_fex_package
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/docs/manual.pdf .
        # MatLab FEX file 
        COMMAND "${Java_JAR_EXECUTABLE}" cfM
            mtoc++_mlfex_${MTOC++_VERSION}.zip cmake/ src/ tools/ test/ CMakeLists.txt INSTALL manual.pdf
        COMMAND ${CMAKE_COMMAND} -E remove manual.pdf
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
    add_custom_target(update_website
        # Copy the documentation
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/docs ${WS_SRC}/docs
        # Copy the license file
        COMMAND ${CMAKE_COMMAND} -E copy LICENSE ${WS_SRC}/License.txt
        DEPENDS create_sourcetar create_win_binaries_packages
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()

INSTALL(TARGETS mtocpp mtocpp_post DESTINATION bin)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/License.txt DESTINATION ${CUSTOM_DOC_DIR})
#INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/mtocpp.conf.example DESTINATION ${CUSTOM_DOC_DIR})
INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs/ DESTINATION ${CUSTOM_DOC_DIR})

ENABLE_TESTING()
# add test target: test examples (unix only so far)
IF (UNIX)
	ADD_TEST(MTOCPP_TEST "${CMAKE_CURRENT_BINARY_DIR}/test.sh")
	SET_TESTS_PROPERTIES(MTOCPP_TEST PROPERTIES FAIL_REGULAR_EXPRESSION "(failed)")
ENDIF()

ADD_TEST(NAME MTOCPP_DOXYTEST COMMAND ${DOXYGEN_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/test/doxygen.conf")

# enable dashboard scripting
INCLUDE (CTest)
SET (CTEST_PROJECT_NAME "MTOC++")

# build a CPack driven installer package
SET (CPACK_GENERATOR "DEB;TGZ")
SET (CPACK_SOURCE_GENERATOR "TGZ")
SET (CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
SET (CPACK_PACKAGE_VERSION_MAJOR "${MTOC++_VERSION_MAJOR}")
SET (CPACK_PACKAGE_VERSION_MINOR "${MTOC++_VERSION_MINOR}")
SET (CPACK_PACKAGE_VENDOR "MDDW")
SET (CPACK_PACKAGE_CONTACT "Martin Drohmann <mdrohmann@uni-muenster.de>, Daniel Wirtz <daniel.wirtz@simtech.uni-stuttgart.de>")
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
