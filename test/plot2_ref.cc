#include "rectgrid.m"
namespace grid{
namespace rect{
mlhsInnerSubst<void> grid::rect::rectgrid::plot(::plot_params params) {


/*  Bernard Haasdonk 9.5.2007
*/


if (nargin <2)
  params = [];
end;

/*  simply forward the call
*/

p = plot_polygon_grid(grid,params);
/* */
/** \docupdate 
*/


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
