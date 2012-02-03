class classA
  :public ::general::reference::classB,
   public ::a::b::c,
   public ::d::e::f,
   public ::g::h::i,
   public ::grid::rect::rectgrid {
/** @class "classA"
  * @ingroup test
  * @brief  help for classA
  *
  *
  *  bigger help for classA
  *
 *
  * @note This class has the class property <tt>Sealed</tt> and cannot be derived from.*/


protected:

::gridbase::gridbase mixed_access;
/** @var mixed_access
  * @brief  variable  storing a grid.
  *
  *
 *
  * @note This property has the MATLAB attribute @c Transient set to true.
  * @note This property has non-unique access specifier: <tt>SetAccess = private, GetAccess = protected</tt>
  * @note <a href="http://www.mathworks.de/help/techdoc/matlab_oop/brjjwby.html">Matlab documentation of property attributes.</a>
  */

matlabtypesubstitute mixed_access2 = 'test';
/** @var mixed_access2
  * @brief  longer help with @f$default@f$ value
  *  what is this??
  *
  *
  *  can we do some special stuff??
  *  @verbatim
      a= b;
      c= d;
     @endverbatim
  *
 *
  * @note This property has the MATLAB attribute @c Transient set to true.
  * @note This property has non-unique access specifier: <tt>SetAccess = private, GetAccess = protected</tt>
  * @note <a href="http://www.mathworks.de/help/techdoc/matlab_oop/brjjwby.html">Matlab documentation of property attributes.</a>
  * <br/>@b Default: 'test'
*/

::SpecialType DataStoreDirectory = '';
/** @var DataStoreDirectory
  * @brief  This documentation is a test for the type keyword.
  *
  *
  *  This variable has a special type
  *   @b Default: empty string 
  *
 *
  * @note This property has the MATLAB attribute @c Transient set to true.
  * @note This property has non-unique access specifier: <tt>SetAccess = private, GetAccess = protected</tt>
  * @note <a href="http://www.mathworks.de/help/techdoc/matlab_oop/brjjwby.html">Matlab documentation of property attributes.</a>
  */

matlabtypesubstitute SomeProp = struct('xi',[],'ti',[],'mui',[]);
/** @var SomeProp
  * @brief SomeProp
  *
  *
 *
  * @note This property has the MATLAB attribute @c Transient set to true.
  * @note This property has non-unique access specifier: <tt>SetAccess = private, GetAccess = protected</tt>
  * @note <a href="http://www.mathworks.de/help/techdoc/matlab_oop/brjjwby.html">Matlab documentation of property attributes.</a>
  * <br/>@b Default: struct('xi',[],'ti',[],'mui',[])
*/

matlabtypesubstitute SomeOtherProp = struct(  \
      'xi', [], 'ti',   \
      []);
/** @var SomeOtherProp
  * @brief SomeOtherProp
  *
  *
 *
  * @note This property has the MATLAB attribute @c Transient set to true.
  * @note This property has non-unique access specifier: <tt>SetAccess = private, GetAccess = protected</tt>
  * @note <a href="http://www.mathworks.de/help/techdoc/matlab_oop/brjjwby.html">Matlab documentation of property attributes.</a>
  * <br/>@b Default: struct(  \
      'xi', [], 'ti',   \
      [])
*/

matlabtypesubstitute SteadyStates = [[0, 9.8153e-4, 0.1930]*models.pcd.BasePCDSystem.xa0  \
      [0, 3.0824e-5, 0.1713]*models.pcd.BasePCDSystem.ya0  \
      [.2, 0.1990, 0.0070]*models.pcd.BasePCDSystem.xi0  \
      [.2, 0.2, 0.0287]*models.pcd.BasePCDSystem.yi0];
/** @var SteadyStates
  * @brief  variable with very long default value
  *
  *
 *
  * @note This property has the MATLAB attribute @c Transient set to true.
  * @note This property has non-unique access specifier: <tt>SetAccess = private, GetAccess = protected</tt>
  * @note <a href="http://www.mathworks.de/help/techdoc/matlab_oop/brjjwby.html">Matlab documentation of property attributes.</a>
  * <br/>@b Default: [[0, 9.8153e-4, 0.1930]*models.pcd.BasePCDSystem.xa0  \
      [0, 3.0824e-5, 0.1713]*models.pcd.BasePCDSystem.ya0  \
      [.2, 0.1990, 0.0070]*models.pcd.BasePCDSystem.xi0  \
      [.2, 0.2, 0.0287]*models.pcd.BasePCDSystem.yi0]
*/

matlabtypesubstitute Property_without_semicolon;
/** @var Property_without_semicolon
  * @brief  commented anyways
  *
  *
 *
  * @note This property has the MATLAB attribute @c Transient set to true.
  * @note This property has non-unique access specifier: <tt>SetAccess = private, GetAccess = protected</tt>
  * @note <a href="http://www.mathworks.de/help/techdoc/matlab_oop/brjjwby.html">Matlab documentation of property attributes.</a>
  */


public:
static const matlabtypesubstitute aConstant = 1;
/** @var aConstant
  * @brief  help text
  *
  *
 * <br/>@b Default: 1
*/

static const matlabtypesubstitute bConstant = 2;
/** @var bConstant
  * @brief  help text for bConstant
  *
  *
 * <br/>@b Default: 2
*/

static const matlabtypesubstitute cConstant = 3;
/** @var cConstant
  * @brief  help text for cConstant
  *
  *
 * <br/>@b Default: 3
*/

static const matlabtypesubstitute vectorConst = [ 1, 2, 3 ];
/** @var vectorConst
  * @brief vectorConst
  *
  *
 * <br/>@b Default: [ 1, 2, 3 ]
*/
static const matlabtypesubstitute dConstant = { [ 1, 2, 3, 4], 'test', [ 1 2, [ [3 [3 [3 4] 4] ] ] ] };
/** @var dConstant
  * @brief  test
  *
  *
 * <br/>@b Default: { [ 1, 2, 3, 4], 'test', [ 1 2, [ [3 [3 [3 4] 4] ] ] ] }
*/

static const matlabtypesubstitute dConstant = struct('a', [], 'b', {'c', 'd'}, 'e', [1 2 3]);
/** @var dConstant
  * @brief dConstant
  *
  *
 * <br/>@b Default: struct('a', [], 'b', {'c', 'd'}, 'e', [1 2 3])
*/

public:
matlabtypesubstitute public_access;
/** @var public_access
  * @brief  short help for public_access
  *
  *
 */

matlabtypesubstitute public_access2;
/** @var public_access2
  * @brief  longer help for public_access2
  *
  *
 */

protected:
matlabtypesubstitute protected_access;
/** @var protected_access
  * @brief  short help for protected_access
  *
  *
 */

matlabtypesubstitute protected_access2;
/** @var protected_access2
  * @brief  longer help text for protected_access2
  *
  *
 */

public:

mlhsInnerSubst<matlabtypesubstitute,obj> foo(matlabtypesubstitute b,matlabtypesubstitute c) {

      function private_function

        pause;
      end

      bar;
}
/** @fn mlhsInnerSubst<matlabtypesubstitute,obj> foo(matlabtypesubstitute b,matlabtypesubstitute c)
  * @brief  brief doc for foo
  *
  *
  * @param b    b
  * @param c    c
  *
  * @retval obj    obj
  *
  * @note This method has the MATLAB method attribute @c Hidden set to true.
  * @note <a href="http://www.mathworks.de/help/techdoc/matlab_oop/brjjv0d.html">matlab documentation of method attributes.</a>
  */


mlhsInnerSubst<matlabtypesubstitute,obj> bar(matlabtypesubstitute d,matlabtypesubstitute e) {

      foo;
}
/** @fn mlhsInnerSubst<matlabtypesubstitute,obj> bar(matlabtypesubstitute d,matlabtypesubstitute e)
  * @brief  brief doc for bar
  *
  *
  * @param d    d
  * @param e    e
  *
  * @retval obj    obj
  *
  * @note This method has the MATLAB method attribute @c Hidden set to true.
  * @note <a href="http://www.mathworks.de/help/techdoc/matlab_oop/brjjv0d.html">matlab documentation of method attributes.</a>
  */

mlhsInnerSubst<matlabtypesubstitute,obj> foobar()
   {


     test

}
/** @fn mlhsInnerSubst<matlabtypesubstitute,obj> foobar()
  
  * @brief  last function comment above
  *  brief for foobar
  *
  *
  *  with main docu block
  *  detail for foobar
  *
  * @retval obj    obj
  *
  * @note This method has the MATLAB method attribute @c Hidden set to true.
  * @note <a href="http://www.mathworks.de/help/techdoc/matlab_oop/brjjv0d.html">matlab documentation of method attributes.</a>
  */

mlhsInnerSubst<matlabtypesubstitute,ret> mdecl(matlabtypesubstitute b);

classA(matlabtypesubstitute param1,matlabtypesubstitute param2) {
}
/** @fn classA(matlabtypesubstitute param1,matlabtypesubstitute param2)
  * @brief  bigger constructor
  *
  *
  * @param param1    param1
  * @param param2    param2
  *
  * @note This method has the MATLAB method attribute @c Hidden set to true.
  * @note <a href="http://www.mathworks.de/help/techdoc/matlab_oop/brjjv0d.html">matlab documentation of method attributes.</a>
  */

public:
/* 
mlhsInnerSubst<matlabtypesubstitute,value> protected_access()
   {

      if a==b
        do something;
*//*  the following end needs to be indented correctly
*/
/* 
      end*//*  garble this correctly
 *|
 * \todo this is a test
*/
/* 

}
*/
/** @var protected_access
  * @par Getter is implemented
  * getter enriching property help text of protected_access
  *
  */

/* 
noret::substitute protected_access(matlabtypesubstitute value) {

      a;
}
*/
/** @var protected_access
  * @par Setter is implemented
  * setter comment is parsed too
  *
  */


/* 
noret::substitute DataStoreDirectory(matlabtypesubstitute ds) {
if ~isdir(ds)
        fprintf(" Creating directory %s\n ",ds);
        mkdir(ds);
      end
      setpref(" KERMOR "," DATASTORE ",ds);
      this.DataStoreDirectory= ds;
      fprintf(" Simulation and model data: %s\n ",ds);
}
*/
/** @var DataStoreDirectory
  * @par Setter is implemented
  *DataStoreDirectory
  *
  */

/* 
noret::substitute protected_access2(matlabtypesubstitute value) {

       a;
}
*/
/** @var protected_access2
  * @par Setter is implemented
  *protected access2
  *
  */


public:
static mlhsSubst<mlhsInnerSubst<matlabtypesubstitute,a> ,mlhsInnerSubst<matlabtypesubstitute,b> > static_method(matlabtypesubstitute notthis,matlabtypesubstitute c) {
}
/** @fn mlhsSubst<mlhsInnerSubst<matlabtypesubstitute,a> ,mlhsInnerSubst<matlabtypesubstitute,b> > static_method(matlabtypesubstitute notthis,matlabtypesubstitute c)
  * @brief  a static method
  *
  *
  * @param notthis    notthis
  * @param c    c
  *
  * @retval a    a
  * @retval b    b
  */

static mlhsInnerSubst<matlabtypesubstitute,ret> test(::gridbase::gridbase auto_param,matlabtypesubstitute b,::test2 c) {
}
/** @fn mlhsInnerSubst<matlabtypesubstitute,ret> test(::gridbase::gridbase auto_param,matlabtypesubstitute b,::test2 c)
  * @brief  @copybrief grid::rect::rectgrid::test()
  *
  *
  *  If copydetails/copydoc commands are used, "parameters" and "return
  *  values" are ignored in the derived class, except for the strings
  *  <tt>of type ...</tt> which are used to define the parameter / return value
  *  type.
  * 
  *  @copydetails grid::rect::rectgrid::test()
  * 
  */

public:
static mlhsSubst<mlhsInnerSubst<matlabtypesubstitute,a> ,mlhsInnerSubst<matlabtypesubstitute,b> > static_abstract_method(matlabtypesubstitute this,matlabtypesubstitute c) = 0;
/** @fn mlhsSubst<mlhsInnerSubst<matlabtypesubstitute,a> ,mlhsInnerSubst<matlabtypesubstitute,b> > static_abstract_method(matlabtypesubstitute this,matlabtypesubstitute c)
  * @brief  a static abstract method
  *
  *
  * @param this    this
  * @param c    c
  *
  * @retval a    a
  * @retval b    b
  */


public:

virtual mlhsInnerSubst<::classA::mixed_access,a> abstract_method(matlabtypesubstitute d,matlabtypesubstitute e) = 0;
/** @fn mlhsInnerSubst<::classA::mixed_access,a> abstract_method(matlabtypesubstitute d,matlabtypesubstitute e)
  * @brief  an abstract method comment above
  *  an abstract method comment below
  *
  *
  *  further comments
  *
  * @param d      parameter 1
  * @param e      parameter 2
  *
  * @retval a     test object 
  *  which has a line break in it
  */


virtual mlhsInnerSubst<matlabtypesubstitute,a> undocumented_abstract_method(matlabtypesubstitute b,matlabtypesubstitute f) = 0;
/** @fn mlhsInnerSubst<matlabtypesubstitute,a> undocumented_abstract_method(matlabtypesubstitute b,matlabtypesubstitute f)
  * @brief undocumented abstract method
  *
  *
  * @param b    b
  * @param f    f
  *
  * @retval a    a
  */

virtual mlhsSubst<mlhsInnerSubst<matlabtypesubstitute,b> ,mlhsInnerSubst<matlabtypesubstitute,c> ,mlhsInnerSubst<matlabtypesubstitute,d> > another_undocumented_abstract_method(matlabtypesubstitute b,matlabtypesubstitute c) = 0;
/** @fn mlhsSubst<mlhsInnerSubst<matlabtypesubstitute,b> ,mlhsInnerSubst<matlabtypesubstitute,c> ,mlhsInnerSubst<matlabtypesubstitute,d> > another_undocumented_abstract_method(matlabtypesubstitute b,matlabtypesubstitute c)
  * @brief another undocumented abstract method
  *
  *
  * @param b    b
  * @param c    c
  *
  * @retval b    b
  * @retval c    c
  * @retval d    d
  */

virtual mlhsInnerSubst<matlabtypesubstitute,c> followed_by_document_method(matlabtypesubstitute d,matlabtypesubstitute e) = 0;
/** @fn mlhsInnerSubst<matlabtypesubstitute,c> followed_by_document_method(matlabtypesubstitute d,matlabtypesubstitute e)
  * @brief  documentation for next method
  *
  *
  * @param d    d
  * @param e    e
  *
  * @retval c    c
  */



};



