class classA
  :public classB,
   public classC {
/** @class "classA"
  * @ingroup test
  * @brief  help for classA
  *
  *
  *  bigger help for classA
  *
 */
protected:

matlabtypesubstitute mixed_access;
/** @var mixed_access
 *  short help*/

/** @brief  longer help with default value
  *
  *
 */
matlabtypesubstitute mixed_access2 = 'test';




public:
static const matlabtypesubstitute aConstant = 1;
/** @var aConstant
 *  help text*/

/** @brief  help text for bConstant
  *
  *
 */
static const matlabtypesubstitute bConstant = 2;

static const matlabtypesubstitute cConstant = 3;
/** @var cConstant
 *  help text for cConstant*/


public:
matlabtypesubstitute public_access;
/** @var public_access
 *  short help for public_access*/

/** @brief  longer help for public_access2
  *
  *
 */
matlabtypesubstitute public_access2;


protected:
matlabtypesubstitute protected_access;
/** @var protected_access
 *  short help for protected_access*/

/** @brief  longer help text for protected_access2
  *
  *
 */
matlabtypesubstitute protected_access2;


public:
 classA() {
}
/** @fn classA()
  * @brief  default constructor
  *
  */

 classA(matlabtypesubstitute param1,matlabtypesubstitute param2) {
}
/** @fn classA(matlabtypesubstitute param1,matlabtypesubstitute param2)
  * @brief  bigger constructor
  *
  *
  * @param param1    param1
  * @param param2    param2
  */


protected:
 /*
ret::substitutestart::value::retsubstituteend protected_access() {
}
*/
/** @var protected_access
  * @par Getter is implemented
  * getter enriching property help text of protected_access
  *
  */

/*
noret::substitute protected_access(matlabtypesubstitute value) {
}
*/
/** @var protected_access
  * @par Setter is implemented
  * setter enriching property help text of protected_access
  *
  */


public:
 static rets::substitutestart::a::b::retssubstituteend static_method(matlabtypesubstitute c) {
}
/** @fn rets::substitutestart::a::b::retssubstituteend static_method(matlabtypesubstitute c)
  * @brief  a static method
  *
  *
  * @param c    c
  *
  * @retval a    a
  * @retval b    b
  */


public:
 ret::substitutestart::a::retsubstituteend abstract_method(matlabtypesubstitute d) = 0;
/** @fn ret::substitutestart::a::retsubstituteend abstract_method(matlabtypesubstitute d)
  * @brief  an abstract method
  *
  *
  * @param d    d
  *
  * @retval a    a
  */




}



