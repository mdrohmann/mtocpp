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
 */


protected:

::gridbase::gridbase mixed_access;
/** @var mixed_access
  * @brief  of type ::gridbase::gridbase short help
  *
  *
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
 */

matlabtypesubstitute DataStoreDirectory = '';
/** @var DataStoreDirectory
  * @brief DataStoreDirectory
  *
  *
 */

matlabtypesubstitute SomeProp = struct('xi',[],'ti',[],'mui',[]);
/** @var SomeProp
  * @brief SomeProp
  *
  *
 */


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
/** @var dConstant
  * @brief dConstant
  *
  *
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

ret::substitutestart::obj::retsubstituteend foo(matlabtypesubstitute b,matlabtypesubstitute c) {

      function private_function

        pause;
      end

      bar;
}
/** @fn ret::substitutestart::obj::retsubstituteend foo(matlabtypesubstitute b,matlabtypesubstitute c)
  * @brief  brief doc for foo
  *
  *
  * @param b    b
  * @param c    c
  *
  * @retval obj    obj
  */


ret::substitutestart::obj::retsubstituteend bar(matlabtypesubstitute d,matlabtypesubstitute e) {

      foo;
}
/** @fn ret::substitutestart::obj::retsubstituteend bar(matlabtypesubstitute d,matlabtypesubstitute e)
  * @brief  brief doc for bar
  *
  *
  * @param d    d
  * @param e    e
  *
  * @retval obj    obj
  */

ret::substitutestart::obj::retsubstituteend foobar()
   {


     test

}
/** @fn ret::substitutestart::obj::retsubstituteend foobar()
  
  * @brief  last function comment above
  *  brief for foobar
  *
  *
  *  with main docu block
  *  detail for foobar
  *
  * @retval obj    obj
  */

ret::substitutestart::ret::retsubstituteend mdecl(matlabtypesubstitute b);

classA(matlabtypesubstitute param1,matlabtypesubstitute param2) {
}
/** @fn classA(matlabtypesubstitute param1,matlabtypesubstitute param2)
  * @brief  bigger constructor
  *
  *
  * @param param1    param1
  * @param param2    param2
  */

public:
/* 
ret::substitutestart::value::retsubstituteend protected_access()
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
        fprintf('Creating directory*//* s\n',ds);
*/
/* 
        mkdir(ds);
      end
      setpref('KERMOR','DATASTORE',ds);
      this.DataStoreDirectory= ds;
      fprintf('Simulation and model data:*//* s\n',ds);
*/
/* 
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
static rets::substitutestart::a::b::retssubstituteend static_method(matlabtypesubstitute notthis,matlabtypesubstitute c) {
}
/** @fn rets::substitutestart::a::b::retssubstituteend static_method(matlabtypesubstitute notthis,matlabtypesubstitute c)
  * @brief  a static method
  *
  *
  * @param c    c
  * @param notthis    notthis
  *
  * @retval a    a
  * @retval b    b
  */

static ret::substitutestart::ret::retsubstituteend test(matlabtypesubstitute a,matlabtypesubstitute b,::test2 c) {
}
/** @fn ret::substitutestart::ret::retsubstituteend test(matlabtypesubstitute a,matlabtypesubstitute b,::test2 c)
  * @brief  @copybrief grid::rect::rectgrid::test()
  *
  *
  *  @copydetails grid::rect::rectgrid::test()
  * 
  *  If copydetails/copydoc commands are used, "parameters" and "return
  *  values" are ignored in the derived class, except for the strings
  *  <tt>object of ...</tt> which are used to define the parameter / return value
  *  type.
  * 
  */

public:
static rets::substitutestart::a::b::retssubstituteend static_abstract_method(matlabtypesubstitute this,matlabtypesubstitute c) = 0;
/** @fn rets::substitutestart::a::b::retssubstituteend static_abstract_method(matlabtypesubstitute this,matlabtypesubstitute c)
  * @brief  a static abstract method
  *
  *
  * @param c    c
  * @param this    this
  *
  * @retval a    a
  * @retval b    b
  */


public:

virtual ret::substitutestart::a::retsubstituteend abstract_method(matlabtypesubstitute d,matlabtypesubstitute e) = 0;
/** @fn ret::substitutestart::a::retsubstituteend abstract_method(matlabtypesubstitute d,matlabtypesubstitute e)
  * @brief  an abstract method comment above
  *  an abstract method comment below
  *
  *
  *  further comments
  *
  * @param d      parameter 1
  * @param e      parameter 2
  *
  * @retval a     test of type ::classA::mixed_access
  */



};



