/**
 * @page install mtoc++ installation instructions
 *
 * Make sure you have the latest version of mtoc++, see @ref download. Next step after installation is @ref tools
 *
 * @section inst_req Software requirements and recommendations
 * The following programs need to be available on your machine in order to use mtoc++:
 * - \c doxygen (>=1.7.3): mtoc++ is a filter for doxygen. If not yet available, get it at http://www.doxygen.org
 * - m4: A macro processor http://www.gnu.org/s/m4/ (For Windows we included a m4 executable in the download!)
 *
 * The following programs will highly improve your documentation creation experience if available:
 * - \c dot: A Graphviz tool that allows doxygen to create nice graphics for inheritance trees and collaboration diagrams.
 * - \c latex: Required to use LaTeX processing capabilities of doxygen (e.g. http://www.latex-project.org/ftp.html).
 *  mtoc++ comes with some markups for better latex inclusion into the text flow.
 *  Also, easy inclusion of external latex sources and styles is included in mtoc++'s tools.
 * - \c ghostscript: If using formulas with doxygen and you are not using pdflatex or are on a windows machine, this
 *  is a prerequisite (see http://www.stack.nl/~dimitri/doxygen/install.html#install_bin_windows)
 *
 * If you want to build mtoc++ from source, you will also need:
 * - Ragel: A finite-state machine compiler. Get at http://www.complang.org/ragel
 * - CMake: Cross-platform make. Get at http://www.cmake.org
 *
 * @section inst_binaries Using precompiled binaries
 * @subsection inst_binaries_win Windows users
 *
 * If you are a windows user you can directly download the binaries at @ref download.
 * Then simply place the binaries in a folder of your choice and add them to the PATH environment variable.
 *
 * @note Doxygen and mtoc++ expect certain programs to be available via the PATH environment variable, e.g. \c latex.exe or \c gswin32c.exe
 * must be present in order for doxygen to work. Make sure that you have all requirements available. You can check/change your Windows
 * PATH environment variable via the sequence
 * @code Computer \ Properties \ Advanced system settings \ Environment Variables \ Edit Path @endcode
 * If you intend to use the MatlabDocMaker, you can also copy the binaries into the "documentation configuration files" folder
 * for your/each project, this path will be added to PATH by MatLab locally.
 *
 * We are trying to always compile current Windows binaries for \c mtocpp and \c mtocpp_post and include them for direct download.
 *
 * @note For Windows binaries from this page you might need to install the Microsoft Visual C++ 2010 redistributables,
 * which can be found <a href="http://www.microsoft.com/download/en/confirmation.aspx?id=8328" target="_blank">here</a>.
 *
 * @subsection inst_binaries_unix Unix binaries
 * For unix users we recommend to compile the sources following @ref inst_comp.
 * However, on the download site you can also find some precompiled linux binaries/packages.
 *
 * If you find a matching choice you can use it and all you have to do is to ensure that the binaries can be found on the environment PATH.
 *
 * @section inst_comp Compiling mtoc++ from source
 * Please check the @ref inst_req when you intend to build mtoc++ yourself.
 *
 * mtoc++ is built using the cmake (cross-platform make) tool. This tool is available for both unix and Windows,
 * however, we only tested compiling our sources on linux and MS Visual Studio 2010.
 *
 * For Windows compilation, you need a Windows C++ compiler (e.g. MinGW or Visual Studio). Then running
 * the CMake GUI allows you to choose a compiler, specify any CMake configuration settings and create the
 * makefiles/Visual Studio projects needed for compilation.
 *
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
 * @subsection inst_cust CMake options: Installation folders and customization
 *
 * @note These options are explained for the linux case, for windows the CMake GUI allows to set the relevant options.
 *
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
 * On Windows, dedendent on your compiler, you will either have makefiles for the test cases or a separate Visual Studio project to run the tests.
 *
 * Have fun!
 */
