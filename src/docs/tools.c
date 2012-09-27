/**
 * @page tools Configuration and use of mtoc++
 * @short Help on how to use the tools coming with mtoc++
 *
 * Make sure you have followed the @ref install.
 *
 * As \c mtoc++ itself is only a filter to plug into doxygen, there is little sense in calling the binaries directly.
 * Thus, mtoc++ comes with a series of tools that take over the documentation generation process for different interfaces.
 * Those tools can be found inside the \c <mtoc++-source-dir>/tools folder.
 *
 * @par Contents
 * - @ref tools_config
 *  - @ref config_doxy
 *  - @ref config_mtocpp
 *  - @ref config_latex
 * - @ref tools_docmaker
 * - @ref tools_python
 *
 * @section tools_config Configuring mtoc++ and doxygen
 *
 * As the configuration of doxygen/mtoc++ is independent from the actual tool used we will explain it separately.
 * The involved files can again be found inside the \c /tools/config folder.
 * - \c Doxyfile.m4 - @ref config_doxy
 * - \c mtocpp.conf - @ref config_mtocpp
 * - \c latexextras.m4 - @ref config_latex
 * - \c class_substitutes.c - @ref config_fakeclasses
 *
 *@attention USING MTOC++ DOES NOT EXCLUDE THE REQUIREMENT TO KNOW AND UNDERSTAND DOXYGEN ITSELF!<br>
 * The settings in the "Doxygen.m4" file inside the \c /tools/config folder are a default
 * configuration for Doxygen which we thought might be useful in a MatLab setting/project and 
 * contains some changes in order to make mtoc++ run together with doxygen.
 * We've had lots of feedback and problem reports which actually had to do with settings purely
 * regarding doxygen, so we strongly recommend having a look through @ref config_doxy and the 
 * references therein before contacting us. Thanks!
 *
 * @subsection config_doxy Configuration options for doxygen
 * You must specify your own configuration for doxygen itself, if you want to manually set up mtoc++ with doxygen.
 * In short, this happens by including mtoc++ as a filter for *.m files.
 * See http://www.stack.nl/~dimitri/doxygen/config.html for more information on doxygen configuration.
 *
 * The mtoc++ filter takes exactly two arguments, of which the first is the file to process, and the second is a configuration file
 * that can be set up as described in @ref config_mtocpp.
 * - If you dont want to customize mtoc++, you simply can set the filter target in doxygen to the \c mtocpp binary.
 * - If you want to provide a config file to mtoc++, depending on your platform, you have to write a shell/batch script that
 * is included as filter callback in doxygen's configuration file. Inside the script, the first argument is forwarded to \c mtocpp
 * and the second configuration file path is provided statically in the script.
 *
 * @note We recommend to use the MatlabDocMaker tool described in @ref tools_docmaker, as it does all the fussy configuration stuff for you
 * and even lets you create your project/files documentation from within MatLab!
 *
 * @subsection config_mtocpp Configuration options for the mtoc++ filter
 * The configuration file for the mtoc++ parser.
 *
 * The following is a short list of options that can be specified for the mtoc++ filter.
 * All options are declared by the syntax @code <option> := <value> @endcode and are optional, as the default values are hardcoded into mtoc++.
 * - \c ALL - File Patterns
 * - \c PRINT_FIELDS - Flag indicating whether automatic struct fields or object member documentation is generated. Default \c true.
 * - \c AUTO_ADD_FIELDS - Flag indicating whether undocumented field names are added to documentation. Default \c false.
 * - \c AUTO_ADD_PARAMETERS - Flag indicating whether undocumented parameters and return values are added to documentation
 * with documentation text equal to the parameter / return value name. Default false.
 * - \c AUTO_ADD_CLASS_PROPERTIES - Flag indicating whether undocumented member variables are added to documentation
 * with documentation text equal to the parameter / return value name. Default false.
 * - AUTO_ADD_CLASSES - Flag indicating whether undocumented classes are added to documentation with documentation
 * text equal to the class name. Default \c true.
 * - REMOVE_FIRST_ARG_IN_ABSTRACT_METHODS - Flag indication whether the first argument in abstract non-static methods
 * shall be a this pointer, and therefore removed in the C++ output. Default \c true.
 * - ENABLE_OF_TYPE_PARSING - Flag indicating whether the string "of type" is parsed in the the first two lines of comments.
 * This is equivalent to the @@type tag, but makes the code more readable at some places. Default \c true.
 * - VOID_TYPE_IN_RETURN_VALUES - Flag indicating whether the typename void shall be inserted for return values with no specified type.
 * Default \c false.
 * PRINT_RETURN_VALUE_NAME - Integer flag indicating whether return value names shall be printed in the function synopsis.
 * If this flag is deactivated only the type names are written. The flag can be set to either 0, 1 or 2 and has default value \c 2:
 * 	- 0: means that no return value names shall be printed at all.
 * 	- 1: means that return value names shall be printed for return value lists with more than one element only.
 * 	- 2: means that return value names shall be printed always.
 *
 * Moreover, default descriptions/values for recurring entries like parameters or field names can be specified.
 *
 * @attention Note that the configuration file sections for variables above and rules below have to be separated
 * by a single line containing only a double hash '##'. ONLY use '##' for that purpose.
 *
 * @par Parameter default descriptions
 * Use the syntax
 * @code add(params) = 	<parameter1_name> => """Your parameter1 description text in triple quotes""",
 * 		<parameter2_name> => """Your parameter2 description text in triple quotes"""; @endcode
 * to add default descriptions to parameters of functions or class members.
 *
 * @par Struct field default descriptions
 * Use the syntax
 * @code add(fields) = <field_name> => """Your field description text in triple quotes"""; @endcode
 * to add default descriptions to fields of any struct or class (identified by a ".fieldname" syntax in the MatLab code)
 *
 * @par Extra documentation
 * Use
 * @code add(doc) = """ <some extra doc for all files> """; @endcode
 * to append some extra documentation to each class or files documentation.
 * Use
 * @code add(extra) = """ <text at end of comments> """; @endcode
 * to append text at the end of any comment.
 *
 * @par Global settings for specific files or folder groups
 * More advanced, those settings above can also be made on a group-based setting. The syntax
 * @code
 * glob = <folder or filename (regexp allowed)> {
 * 	<expressions as above>
 * 	glob = <subfolder or files> {
 * 		<expressions as above>
 * 	};
 * }
 * @endcode
 * can be used to specify groups of rules that are applied to any matching file or files in folders.
 * Nesting is possible, too.
 *
 * So for example,
 * @code glob = myfile.m { add(params) = param1 => """ param 1 description """; } @endcode
 * would cause mtoc++ to add the description "param 1 description" to any parameter called \c param1 of a method/function inside the file \c myfile.m.
 *
 * @attention Having common field names specified centrally is a quite convenient way to autogenerate documentation.
 * However, if you use e.g. the same parameter name in a different meaning and forget to explicitly specify the parameter documentation,
 * the default values will be inserted. This possibly leads to more confusion for users than it does help.
 * Furthermore, not specifiying the parameters in the local comments decreases readability of the code. One of mtoc++'s main advantages in
 * combination with doxygen is that code can be commented highly readable in-place!
 *
 * See the file itself for more detailed configuration options and examples.
 *
 * @subsection config_latex Extending default LaTeX environment for doxygen
 * The \c latexextras.m4 file is processed and included into the latex environment available to doxygen during the documentation creation.
 * Insert here any commands or packages that you want latex to know for your documentation formulas.
 *
 * @attention When having errors inside an LaTeX formula, doxygen will complain upon finishing and tell you to look
 * into the _formulas.log/.tex file in the documentation output folder. THIS WARNING COMES ONLY ONE TIME!
 * Upon the next creation run, only changed/new formulas will be re/generated.
 * We considered deleting all formula pngs before each re-creation, but decided not to do this for performance issues.
 * So just make sure you react to latex typos/errors immediately.
 *
 * The default packages that are included by the \c latexextras.m4 are
 * @code \usepackage{amsmath}
 * \usepackage{amssymb}
 * \usepackage{amsfonts}
 * \usepackage{subfig}
 * \usepackage{bbm} @endcode
 *
 * @subsection config_fakeclasses Fake classes for typical MatLab data types
 * The file \c class_substitutes.c includes some class descriptions for typical MatLab data types like handle or logical, but also introduces
 * custom types like colvec or rowvec that can be used with the @@type tag for property, parameter or return value types.
 *
 * Add new classes to this file or change existing ones as you need.
 *
 * @section tools_docmaker Using the MatlabDocMaker
 * The most convenient way of using mtoc++ within your matlab project is to use the MatlabDocMaker class coming with mtoc++.
 * The MatlabDocMaker is a MatLab class that can be directly used from within MatLab in order to create the project documentation.
 *
 * Follow these simple steps in order to quickly get your first documentation:
 * - Place the MatlabDocMaker.m file somewhere on your project's MatLab path.
 * - Make appropriate changes to the MatlabDocMaker.getProjectName and MatlabDocMaker.getProjectVersion methods
 * - Copy the contents of the \c <mtoc++-source-dir>/tools/config folder into e.g. a subfolder of your MatLab project
 * - Call the MatlabDocMaker.setup method and use the folder from the previous step as your "documentation configuration files directory".
 * - Use the MatlabDocMaker.create method to generate your documentation and look at it in a web browser.
 *
 * See the MatlabDocMaker class description for more details on how to use it.
 * @note You may of course keep the MatlabDocMaker.m and the configuration files where you initially placed your mtoc++ source and point to the
 * appropriate directories during setup.<br>
 * However, if you want to use multiple projects with mtoc++ you probably want to have different configurations for each project, so that is why we recommend to create local copies of your
 * tools and configuration within each project.<br>
 * The way the MatlabDocMaker works it can be easily inserted into whatever versioning system your project uses.
 * As it stores important folders in MatLab preferences each developer will still have his local documentation settings.
 *
 * If you want to customize the doxygen behaviour when using the MatlabDocMaker, you need to adjust the \c Doxyfile.m4 file (carefully!).
 * It will get parsed by m4 to replace tags for specific folders etc. and contains any other configuration settings you want doxygen to use.
 * This way, the configuration files can be included into the versioning system as local developers paths are stored outside the configuration file
 * and are provided by the different tools coming with mtoc++.
 *
 * @section tools_python Using the python script from a unix shell
 * @todo We're on it :-)
 */
