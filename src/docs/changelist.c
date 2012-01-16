/**
 * @page changes Changes and new features in mtoc++
 * @short Changelog and new feature list for mtoc++
 *
 * Here are all the changes/new features sorted by versions of mtoc++:
 * - @subpage newfeat01  - @subpage changelog01
 * - @subpage newfeat12  - @subpage changelog12
 * - @subpage newfeat13  - @subpage changelog13
 *
 * @attention The repeated occurence of the new features/changes in this specific site below is just due to the fact that
 * the mtoc++ features/changes themselves have to be written down somewhere. Under usual circumstances those tags below
 * would be placed inside the MatLab files/functions/classes where the actual change happened; see the comments
 * from the MatlabDocMaker as an example. So the list below is not necessarily complete, but the sites referenced above contain all
 * new features / changes!
 *
 * @change{1,3,dw,2012-01-16} Bugfix: The setting EXTRA_PACKAGES in the doxygen configuration file had a forwardslash "/" hardcoded
 * for the inclusion of the latexextras.sty file. However, while doxygen can handle "/" for both unix and windows, latex does not.
 * So the inclusion failed and caused no formulas to be generated on windows. We fixed this by including a new placeholder "_FileSep_"
 * which is being processed by MatlabDocMaker (any any tools to come) and set to the correct file separator character for your platform.
 *
 * @change{1,3,dw,2012-01-14} Bugfix: Moved the mtoc++ developers page declaration into a separate file inside the tools/config folder, so that
 * error messages like "changelog1:13: warning: unable to resolve reference to `dw' for \ref command" do not appear anymore.
 *
 * @new{1,3,md,2012-01-10}
 * - "Bugfix": Allowing the use of the \c AbortSet tag in property declarations, however, to extra action (e.g. inserting
 * a note in documentation) is taken so far.
 * - Some minor modifications for the postprocessor regarding dots '.' and '::'
 *
 * @new{1,3,md,2011-12-16} Allowing multiple lines for default values in property comments & code and added a test case.
 *
 * @change{1,3,md,2011-12-16} Bugfix: On Windows platforms the wrong \c getcwd command was issued and is now fixed.
 *
 * @change{1,3,md,2011-12-13}
 * - Bugfix: Now handling the \b Abstract property correctly (was previously added for \b SetObservable declarations due to copy&paste)
 * - Added a test case for default properties containing semicolons
 * - Changed format for documentation of default properties and parameters
 * - Default arguments for properties are added to the properties documentation block
 * - Bugfix: observable properties have been documented as abstract ones.
 *
 * @change{1,3,dw,2011-12-08} Bugfix: The CUSTOM_DOC_DIR path is not longer extended by a \c docs/ folder.
 *
 * @change{1,3,md,2011-12-04} Bugfix reported by Evgeny Pr on mathworks: allow property definitions not ended by semicolons.
 *
 * @change{1,3,dw,2011-11-29} Added the new fake classes varargin and varargout to the class_substitutes.c file with links to
 * the MatLab online documentation.
 *
 * @new{1,3,dw,2011-11-28} Started mtoc++ 1.3.
 *
 * @change{1,2,md,2011-11-28}
 * Allow long (including line breaks) default values for properties
 *
 * @new{1,2,dw,2011-11-27}
 * - Reordered the Doxyfile.m4 so that changes from our side are all collected to the bottom. This makes keeping custom settings 
 * over different versions easier.
 *
 * @new{1,2,dw,2011-11-25} Included a file class_substitutes.c into the config directory that introduces fake classes for
 * common matlab data types.
 *
 * @change{1,2,md,2011-11-17} Updated the test reference files
 *
 * @new{1,2,dw,2011-11-07} Created the initial mtoc++ documentation structure
 *
 * @change{1,2,dw,2011-11-07} Reordered the source code files and tools in more concise folders.
 *
 * @page newfeat01 New features in mtoc++ 0.1
 * @short Demo features of the demo classes and examples
 *
 * See also @ref changelog01
 *
 * @page changelog01 Changes in mtoc++ 0.1
 * @short Demo changes of the demo classes and examples
 *
 * See also @ref newfeat01
 *
 * @page newfeat12 New features in mtoc++ 1.2
 * @short First "stable" release with windows/unix support.
 *
 * See also @ref changelog12
 *
 *
 * @page changelog12 Changes in mtoc++ 1.2
 * @short First "stable" release with windows/unix support.
 *
 * See also @ref newfeat12
 *
 * @page newfeat13 New features in mtoc++ 1.3
 * @short Current development
 *
 * See also @ref changelog13
 *
 *
 * @page changelog13 Changes in mtoc++ 1.3
 * @short Current development
 *
 * See also @ref newfeat13
 *
 */
