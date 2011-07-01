/**
@mainpage KerMor Software Documentation
@section intro Introduction
KerMor is a MATLAB&copy; library providing routines for model order reduction
of dynamical systems using subspace projection and kernels methods.
Check out the Modules pages to get an overview of the different functionalities.

KerMor makes extensive use of object oriented programming (OOP), basic information can be found
at http://www.mathworks.com/products/matlab/object_oriented_programming.html 
and advanced techniques can be found at http://www.advancedmcode.org/object-oriented-programming-in-matlab.html.

@section learning How To get started
@subsection mp_dl Downloading KerMor
 - Obtain a copy via git using @verbatim git clone <agh-root-folder>/git/kermor <somelocalfolder>@endverbatim
 - Check out the @ref testing and @ref models sections.

@subsection mp_install Installation
When first downloading the KerMor software you need to run the installation script KerMor.install from the matlab console.
This will set up the environment variables and compile any mex functions used within KerMor.
You will be asked for some directories during the installation script.

In order to use 3rdParty programs you need to compile them externally and place appropriate symlinks in the @verbatim <source>/3rdparty @endverbatim directories.

@subsection mp_docs Documentation
- If desired create your own documentation: details can be found at the @ref docpage page
- Check out the @ref newfeat and @ref changelog pages for latest informations

@subsection mp_startup Start of KerMor
KerMor comes with a startup script KerMor.start that initializes any variables, static classes and parallel computing at the beginning.
If you have an automatically called script upon matlab startup you can add the path of your KerMor source directory to the PATH variable and call KerMor.start directly.

When you stop working with KerMor it is recommended to call KerMor.stop in order to cleanly shut down the application and free resources. However,
if you quit matlab after that anyways you dont need to call the stop method.
*/
