======
MTOC++
======

This somewhat larger project allows to create documentation for MatLab files
and classes (including packages) using a doxygen_ filter named mtoc++.
Moreover, a tool/class named ``MatlabDocMaker`` allows to create the documentation
from within MatLab.  For Windows, Mac and Unix!

The project is also hosted on the `Mathworks File Exchange`_.

Rough feature list
==================

- Supports classes and packages
- Also @folders for classes
- Abstract & Static methods
- Special tags "@type" and "@default" for method parameters and return values
  for more expressive documentation
- Automatic detection of used fields and appropriate documentation
- Default documentation for methods, parameters, return values etc
- detection of getter & setter methods
- included latex support and shortcuts for higher readability in plain text
  (e.g. `\sqrt{x}` is like @f$\sqrt{x}@f$)
- support for MatLab events
- HTML and LaTeX output
- much more...

Documentation
=============

The complete documentation can be found at `here
<http://www.morepas.org/software/mtocpp/docs/index.html>`_, but is also
included in the download. Detailed instructions for installation and
configuration can be found therein, however, here are the basic steps needed to
get started:

Installation
============

Unix / MAC OS
-------------

- download & unzip in a folder.

  .. code:: bash

     tar xzf mtocpp.tar.gz
  ..

- Create a ``build`` folder inside and change to that dir

  .. code:: bash

     mkdir build; cd build
  ..

- Compile the source code

  .. code:: bash

     cmake ..
     make
  ..

- You can find the the executables ``mtocpp`` and ``mtocpp_post`` inside the
  ``build`` folder, the documentation in ``docs``. Optionally you can install the 

Windows
-------

Binaries for MTOC++ are distributed through the official `download page`_.
Unpack the archive and add the binaries to your ``PATH``.


Usage
=====

1. Place the ``MatlabDocMaker.m`` in your project's MatLab path

2. Copy the contents of the ``<mtoc++-source-dir>/tools/config`` folder into
   e.g. a subfolder of your MatLab project

3. place binaries (win or unix) on PATH environment or inside the folder
   created in the last step

4. Call the MatlabDocMaker.setup method and use the folder from the previous steps as your "documentation configuration files directory".

5. Use the MatlabDocMaker.create method to create your documentation!

Developers
----------

Martin Drohmann and `Daniel Wirtz`_

We welcome any improvement suggestions and critics.

.. _Mathworks File Exchange: http://www.mathworks.com/matlabcentral/fileexchange/33826-mtoc++-doxygen-filter-for-matlab-and-tools
.. _doxygen: http://www.doxygen.org
.. _download page: http://www.morepas.org/software/mtocpp/docs/download.html
.. _Daniel Wirtz: http://www.mechbau.uni-stuttgart.de/ls2/jrg/people/academic_staff/wirtz/
