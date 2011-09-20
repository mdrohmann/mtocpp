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
  * @note This property has the MATLAB parameter <tt>Transient</tt> set to true.
  * @note This property has non-unique access specifier: SetAccess = privateGetAccess = protected
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
  * @note This property has the MATLAB parameter <tt>Transient</tt> set to true.
  * @note This property has non-unique access specifier: SetAccess = privateGetAccess = protected
  */

::SpecialType DataStoreDirectory = '';
/** @var DataStoreDirectory
  * @brief  This documentation is a test for the type keyword.
  *
  *
  *  This variable has a special type
  *  
  *
 *
  * @note This property has the MATLAB parameter <tt>Transient</tt> set to true.
  * @note This property has non-unique access specifier: SetAccess = privateGetAccess = protected
  */

matlabtypesubstitute SomeProp = struct('xi',[],'ti',[],'mui',[]);


public:
static const matlabtypesubstitute aConstant = 1;
/** @var aConstant
  * @brief  help text
  *
  *
 */

static const matlabtypesubstitute bConstant = 2;
/** @var bConstant
  * @brief  help text for bConstant
  *
  *
 */

static const matlabtypesubstitute cConstant = 3;
/** @var cConstant
  * @brief  help text for cConstant
  *
  *
 */

static const matlabtypesubstitute dConstant = { [ 1, 2; 3, 4]; 'test'; [ 1 2; [ [3 [3 [3 4] 4] ] ] ] };
/** @var dConstant
  * @brief  test
  *
  *
 */

static const matlabtypesubstitute dConstant = struct('a', [], 'b', {'c', 'd'}, 'e', [1 2 3]);

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

mlhsInnerSubst<void> foo(matlabtypesubstitute b,matlabtypesubstitute c) {

      function private_function

        pause;
      end

      bar;
}
/** @fn mlhsInnerSubst<void> foo(matlabtypesubstitute b,matlabtypesubstitute c)
  * @brief  brief doc for foo
  *
  *
  *
  *
  * @note This method has the MATLAB method property <tt>Hidden</tt> set to true.
  */


mlhsInnerSubst<void> bar(matlabtypesubstitute d,matlabtypesubstitute e) {

      foo;
}
/** @fn mlhsInnerSubst<void> bar(matlabtypesubstitute d,matlabtypesubstitute e)
  * @brief  brief doc for bar
  *
  *
  *
  *
  * @note This method has the MATLAB method property <tt>Hidden</tt> set to true.
  */

mlhsInnerSubst<void> foobar()
   {


     test

}
/** @fn mlhsInnerSubst<void> foobar()
  
  * @brief  last function comment above
  *  brief for foobar
  *
  *
  *  with main docu block
  *  detail for foobar
  *
  *
  * @note This method has the MATLAB method property <tt>Hidden</tt> set to true.
  */

mlhsInnerSubst<void> mdecl(matlabtypesubstitute b);

classA(matlabtypesubstitute param1,matlabtypesubstitute param2) {
}
/** @fn classA(matlabtypesubstitute param1,matlabtypesubstitute param2)
  * @brief  bigger constructor
  *
  *
  *
  * @note This method has the MATLAB method property <tt>Hidden</tt> set to true.
  */

public:
/* 
mlhsInnerSubst<void> protected_access()
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
        fprintf("Creating directory %s\n",ds);
        mkdir(ds);
      end
      setpref("KERMOR","DATASTORE",ds);
      this.DataStoreDirectory= ds;
      fprintf("Simulation and model data: %s\n",ds);
}
*/

/* 
noret::substitute protected_access2(matlabtypesubstitute value) {

       a;
}
*/


public:
static mlhsSubst<mlhsInnerSubst<void,a> ,mlhsInnerSubst<void,b> > static_method(matlabtypesubstitute notthis,matlabtypesubstitute c) {
}
/** @fn mlhsSubst<mlhsInnerSubst<void,a> ,mlhsInnerSubst<void,b> > static_method(matlabtypesubstitute notthis,matlabtypesubstitute c)
  * @brief  a static method
  *
  *
  *
  */

static mlhsInnerSubst<void> test(::gridbase::gridbase auto_param,matlabtypesubstitute b,::test2 c) {
}
/** @fn mlhsInnerSubst<void> test(::gridbase::gridbase auto_param,matlabtypesubstitute b,::test2 c)
  * @brief  @copybrief grid::rect::rectgrid::test()
  *
  *
  *  If copydetails/copydoc commands are used, "parameters" and "return
  *  values" are ignored in the derived class, except for the strings
  *  <tt>object of ...</tt> which are used to define the parameter / return value
  *  type.
  * 
  *  @copydetails grid::rect::rectgrid::test()
  * 
  */

public:
static mlhsSubst<mlhsInnerSubst<void,a> ,mlhsInnerSubst<void,b> > static_abstract_method(matlabtypesubstitute this,matlabtypesubstitute c) = 0;
/** @fn mlhsSubst<mlhsInnerSubst<void,a> ,mlhsInnerSubst<void,b> > static_abstract_method(matlabtypesubstitute this,matlabtypesubstitute c)
  * @brief  a static abstract method
  *
  *
  *
  */


public:

virtual mlhsInnerSubst<::classA::mixed_access> abstract_method(matlabtypesubstitute d,matlabtypesubstitute e) = 0;
/** @fn mlhsInnerSubst<::classA::mixed_access> abstract_method(matlabtypesubstitute d,matlabtypesubstitute e)
  * @brief  an abstract method comment above
  *  an abstract method comment below
  *
  *
  *  further comments
  *
  * @param d      parameter 1
  * @param e      parameter 2
  *
  * @retval a     test 
  */


virtual mlhsInnerSubst<void> undocumented_abstract_method(matlabtypesubstitute b,matlabtypesubstitute f) = 0;

virtual mlhsSubst<mlhsInnerSubst<void,b> ,mlhsInnerSubst<void,c> ,mlhsInnerSubst<void,d> > another_undocumented_abstract_method(matlabtypesubstitute b,matlabtypesubstitute c) = 0;

virtual mlhsInnerSubst<void> followed_by_document_method(matlabtypesubstitute d,matlabtypesubstitute e) = 0;
/** @fn mlhsInnerSubst<void> followed_by_document_method(matlabtypesubstitute d,matlabtypesubstitute e)
  * @brief  documentation for next method
  *
  *
  *
  */



};



