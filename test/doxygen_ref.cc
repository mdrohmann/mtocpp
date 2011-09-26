mlhsInnerSubst<matlabtypesubstitute,rv> doxygen(::testnamespace::testclass param1,matlabtypesubstitute param2,::gridbase auto_param) {


/*  After the first non-comment line the function body begins:
*/


/** Comment blocks starting with %| are interpreted as Doxygen documentation
 *  blocks and can include doxygen commands like
*/


/** \todo There needs to be done something in this file
*/


/*  fields of parameters that are used in the function body are added to the
 * required fileds list automatically, if they are not documentated yet.
*/

param1.auto_added;

param2.auto_added;

/*  fields of return values that are assigned somewhere in the function body are
 * also added automatically to the list of generated fields
*/

rv.auto_added= 1;
rv.sub.auto_added= 2;

param1.sub.auto_added;

auto_param.auto_field;

}
/** @file "./doxygen.m"
  * @ingroup test
  * @brief  Here comes a short description text
  */
/** @fn mlhsInnerSubst<matlabtypesubstitute,rv> doxygen(::testnamespace::testclass param1,matlabtypesubstitute param2,::gridbase auto_param)
  * @brief  Here comes a short description text
  *
  *
  *  After the first empty documentation line, paragraphs of the detailed
  *  description begin.
  * 
  * @par  Here, you have the following formatting possibilites
  *  Adding LaTeX code in the text with \verbatim @f$ \sum_{n=0}^N \frac{1}{n} @f$ \endverbatim
  *  @f$ \sum_{n=0}^N \frac{1}{n} @f$ or as an
  *  equation block with @verbatim @f[ \sum_{n=0}^N \frac{1}{n}. @f] @endverbatim.
  *  @f[ \sum_{n=0}^N \frac{1}{n}. @f] Doxygen commands
  *  always begin with an at-character(@) OR a backslash(\\).
  * 
  *  Words prepended by \\c are written in a \c type-writer font.
  *  Words prepended by \\b are written in a \b bold font.
  *  Words prepended by \\em are written in an \em emphasized font.
  * 
  *  Blocks starting with @@verbatim or @@code and are ended with @@endverbatim or
  *  @@endcode are written unformatted in a type-writer font and are not
  *  interpreted by doxygen.
  * 
  * @par  Example
  *  @verbatim
                    /| |\
                   ( |-| )
                    ) " (
                   (>(Y)<)
                    )   (
                   /     \
                  ( (m|m) )  hjw
                ,-.),___.(,-.\`97
                \`---\'   \`---\'
     @endverbatim
  * 
  * @par  Paragaphs starting with line ending with a double-colon
  *  are started with a bold title line
  * 
  *  If, however, a double-colon at the end of a line is succeeded by: 
  *  whitespace characters, like spaces or tabulators the line is not written in a
  *  bold font.
  * 
  *  @note As regularly commands like @verbatim \c @f$, @f$ @f[, @f] @endverbatim
  *  look too distracting in matlab documentation output, the following shortcust
  *  exist: The doxygen filter translates
  *   - @verbatim 'word' to \c word @endverbatim resulting in the output: <tt>word</tt>,
  *   - @verbatim `x` to @f$x@f$ @endverbatim resulting in the output: @f$x@f$ and 
  *   - @verbatim ``x`` to @f[x.@f] @endverbatim resulting in the output: @f[x@f].
  * 
  *  You therefore need to be careful with the use of characters @verbatim ' `
     @endverbatim. If you want to say something about the transposed of a Matrix
  *  <tt>A</tt>, better do it in a Tex-Environment as @f$A' * B'@f$ or in a verbatim/code
  *  environment as
  *  @code A' * B' @endcode
  * 
  *  Listings can be added by prepending lines with a dash(-)
  *   - list 1 item which can also include
  *    newlines
  *   - list 2 item
  *     - and they can be nested
  *     - subitem 2
  *     .
  *   - list 3 item
  * 
  *  and they are ended by an empty documentation line.
  * 
  *  Enumerations can be added by prepending lines with a dash and hash (-#)
  *   -# first item
  *   -# second item
  *   -# third item
  * 
  *  Lines beginning with the words "Parameters" or "Return values" start a block
  *  of argument respectively return argument descriptions.
  * 
  *  A line beginning with the words "Required fields of", "optional fields of" or
  *  "generated fields of" start a block for descriptions for fields used by the
  *  parameters or generated for the return values.
  * 
  * 
  *
  * @param auto_param     object  which is not used! This documentation is added automatically! 
  * @param param1     first parameter 
  * @param param2    param2
  *
  * @retval rv     return value
  *
  * @par Required fields of auto_param:
  * @arg \c auto_field&nbsp;&mdash;&nbsp;    @copybrief ::gridbase::auto_field
  *
  * @par Required fields of param1:
  * @arg \c auto_added&nbsp;&mdash;&nbsp;    @copybrief ::testnamespace::testclass::auto_added
  * @arg \c sub.auto_added&nbsp;&mdash;&nbsp;    @copybrief ::testnamespace::testclass::sub.auto_added
  * @arg \c test&nbsp;&mdash;&nbsp;     Description for required field param1.test
  *
  * @par Required fields of param2:
  * @arg \c auto_added&nbsp;&mdash;&nbsp;    auto added
  *
  * @par Optional fields of param2:
  * @arg \c test2&nbsp;&mdash;&nbsp;     Description for optional field param2.test2
  *
  * @par Generated fields of rv:
  * @arg \c RB&nbsp;&mdash;&nbsp;     Description for generated field rv.RB
  * @arg \c auto_added&nbsp;&mdash;&nbsp;    auto added
  * @arg \c sub.auto_added&nbsp;&mdash;&nbsp;    sub.auto added
  */
mlhsInnerSubst<matlabtypesubstitute,c> mtoc_subst_doxygen_m_tsbus_cotm_second_function_without_docu(matlabtypesubstitute a,matlabtypesubstitute b) {

}
/** @fn mlhsInnerSubst<matlabtypesubstitute,c> mtoc_subst_doxygen_m_tsbus_cotm_second_function_without_docu(matlabtypesubstitute a,matlabtypesubstitute b)
  * @brief second function without docu
  *
  *
  * @param a    a
  * @param b    b
  *
  * @retval c    c
  */
mlhsSubst<mlhsInnerSubst<matlabtypesubstitute,d> ,mlhsInnerSubst<matlabtypesubstitute,e> ,mlhsInnerSubst<matlabtypesubstitute,f> > mtoc_subst_doxygen_m_tsbus_cotm_third_function_with_sev_retvals(::rectgrid auto_param) {


body(string, with, double quote, and percent sign, " '%s'}")/*  a real comment }
*/


}
/** @fn mlhsSubst<mlhsInnerSubst<matlabtypesubstitute,d> ,mlhsInnerSubst<matlabtypesubstitute,e> ,mlhsInnerSubst<matlabtypesubstitute,f> > mtoc_subst_doxygen_m_tsbus_cotm_third_function_with_sev_retvals(::rectgrid auto_param)
  * @brief  a third (private) function in the test file with serveral return values
  *
  *
  * @param auto_param     object  which is not used! This documentation is added automatically! 
  *
  * @retval d     a return value
  * @retval e    e
  * @retval f    f
  */
mlhsSubst<mlhsInnerSubst<matlabtypesubstitute,d> ,mlhsInnerSubst<matlabtypesubstitute,e> ,mlhsInnerSubst<matlabtypesubstitute,f> > mtoc_subst_doxygen_m_tsbus_cotm_third_function_without_parameters()
   {


/** \docupdate
*/


}
/** @fn mlhsSubst<mlhsInnerSubst<matlabtypesubstitute,d> ,mlhsInnerSubst<matlabtypesubstitute,e> ,mlhsInnerSubst<matlabtypesubstitute,f> > mtoc_subst_doxygen_m_tsbus_cotm_third_function_without_parameters()
  
  * @brief  a third (private) function in the test file without parameters
  *
  *
  * @retval d     a return value
  * @retval e    e
  * @retval f    f
  */
