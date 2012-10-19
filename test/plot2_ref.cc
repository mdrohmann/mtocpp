#include "rectgrid.m"
namespace grid{
namespace rect{

/* NB: This source code has been filtered by the mtocpp executable.
 * It comprises code that can be interpreted by the doxygen documentation
 * tool. On the other hand, it can neither be interpreted by MATLAB, nor
 * can it be compiled with a C++ compiler.
 * Except for the comments, the function bodies of your M-file functions
 * are untouched. Therefor, you might want to activate the
 * FILTER_SOURCE_FILES doxygen switch. Then, links in the doxygen generated
 * documentation to the source code of functions and class members refer to
 * the correct spots in the source code browser.
 * BUT: The line numbers most likely do not correspond to the line numbers in
 * the original MATLAB source files. */
mlhsInnerSubst<void> grid::rect::rectgrid::plot(::plot_params params) {


/*  Bernard Haasdonk 9.5.2007 */

if (nargin <2)
  params = [];
end;

/*  simply forward the call */
p = plot_polygon_grid(grid,params);
/* */
/** \docupdate  */

}
/** @fn mlhsInnerSubst<void> grid::rect::rectgrid::plot(::plot_params params)
  * @brief  plot function
  *
  *
  *  plot of a rectgrid via plot_polygon_grid
  *  see help plot_polygon_grid for further information
  *
  * @param params     object 
  *
  * @synupdate Syntax needs to be updated! 
  */

};
};
