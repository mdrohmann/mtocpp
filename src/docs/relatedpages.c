// ##################### Getting started ########################
/**
 * @page getting_started Get started with mtoc++
 * @short Information on how to obtain and install mtoc++
 *
 * @section gs_reqs Software requirements
 * - @b Doxygen: mtoc++ is pretty useless witout doxygen. If not yet available, get it at http://www.doxygen.org
 *
 * If you want to compile your own version of mtoc++, the following programs need to be available on your machine:
 * - @b Ragel: A finite-state machine compiler. Get at http://www.complang.org/ragel
 * - @b CMake: Cross-platform make. Get at http://www.cmake.org
 * 
 * @section gs_dl Downloading mtoc++
 * The sources for mtoc++ will be accessible as 
 * - Source tarball 
 * - Via the git versioning system
 * - Precompiled Debian packages
 * 
 * @section gs_install Installation
 * After downloading the source code you need to configure and compile mtoc++. 
 * The following procedure is an example of how to perform those steps:
 * -# Extract the tarball via @code tar -xcvf mtocpp.tar.gz @endcode if you downloaded it. When using git, simply change to the repository root folder.
 * -# Create a folder "build" via @code mkdir build @endcode and enter it @code cd build @endcode
 * -# Now run @code cmake .. @endcode which starts the configuration and should end with @verbatim -- Build files have been written to: <src-dir>/build @endverbatim
 * -# Finally run @code make install @endcode in the same folder.
 *
 * @subsection gs_install_custom Installation customization
 * If you want the "make install" command to copy the binaries and documentation to different locations, you can choose them by setting the following variables:
 * - \c CMAKE_INSTALL_PREFIX: Set this to whatever location you want mtoc++ to be installed. Note that the binaries are copied into a "bin" folder in that folder in order to comply with linux standards.
 * - \c CUSTOM_DOC_DIR: This value is "CMAKE_INSTALL_PREFIX/share/doc/mtocpp" per default.
 *
 * So typing @code cmake -DCMAKE_INSTALL_PREFIX="/my/root/dir" -DCUSTOM_DOC_DIR="/my/docs" .. @endcode in step 3. above
 * will copy the binaries to @code /my/root/dir/bin @endcode and the documentation to @code /my/docs @endcode
 *
 * @section gs_docs Documentation
 * As you might have guessed from the installation part, the current versions' documentation is automatically created when compiling mtoc++.
 *
 */

// ##################### Licensing ########################
/**
* @page licensing mtoc++ license conditions
* @short This software is available under the GNU GPL license
*
* This program is free software: you can redistribute it and/or modify 
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*/