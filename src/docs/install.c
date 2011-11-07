/**
 * @page install mtoc++ installation instructions
 *
 * Make sure you have the latest version of mtoc++, see @ref download. Next step after installation is @ref tools
 *
 * @section inst_req Software requirements
 * The following programs need to be available on your machine in order to build mtoc++:
 * - Tar: Tar archive tool http://www.gnu.org/software/tar/
 * - Ragel: A finite-state machine compiler. Get at http://www.complang.org/ragel
 * - CMake: Cross-platform make. Get at http://www.cmake.org
 * - Doxygen: mtoc++ is pretty useless witout doxygen. If not yet available, get it at http://www.doxygen.org
 *  (this is not really a requirement for compiling but we made cmake check for doxygen)
 *
 * In order to use mtoc++ most conveniently you also need
 * - m4: A macro processor http://www.gnu.org/s/m4/
 * - latex: Required to use LaTeX processing capabilities of doxygen (e.g. http://www.latex-project.org/ftp.html)
 *
 *
 * @section inst_comp Compiling mtoc++
 * The following procedure is an example of how to compile mtoc++ on a linux machine:
 * @code tar -xcvf mtocpp.tar.gz
 * cd mtocpp
 *
 * # Create build folder (optional, but more clean)
 * mkdir build
 * cd build
 *
 * # Run cmake
 * cmake ..
 * make install
 * @endcode
 *
 * @subsection inst_cust Installation folders and customization
 * The default value for the install prefix is \c /usr/local, so the mtocpp binaries \c mtocpp and \c mtocpp_post go to \c /usr/local/bin
 * and the documentation is created inside \c /usr/local/share/doc/mtocpp.
 *
 * If you want the "make install" command to copy the binaries and documentation to different locations, you can choose them by setting the following variables:
 * - CMAKE_INSTALL_PREFIX: Set this to whatever location you want mtoc++ to be installed. Note that the binaries are effectively copied into "CMAKE_INSTALL_PREFIX/bin" in order to comply with linux standards.
 * - CUSTOM_DOC_DIR: This value is "CMAKE_INSTALL_PREFIX/share/doc/mtocpp" per default.
 *
 * So typing
 * @code cmake -DCMAKE_INSTALL_PREFIX="/my/root/dir" -DCUSTOM_DOC_DIR="/my/docs" @endcode
 * will copy the binaries to \c /my/root/dir/bin and the documentation to \c /my/docs.
 *
 * If you left the \c CUSTOM_DOC_DIR flag empty the documentation would have gone to \c /my/root/dir/share/doc/mtocpp
 *
 * @section inst_test Testing
 * mtoc++ comes with some unit tests to check for e.g. successful compilation.
 * Run the tests by typing
 * @code make test @endcode
 * in the same folder where you called \c cmake.
 *
 * Have fun!
 */
