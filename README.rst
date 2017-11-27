========
CppUtils
========

-----------------------------------------------------------------------------------------
A template repository to quick-start C++ development.
-----------------------------------------------------------------------------------------

.. image:: https://travis-ci.org/mbedded-ninja/CppTemplate.svg?branch=master
	:target: https://travis-ci.org/mbedded-ninja/CppTemplate

---------------
Automatic Build
---------------

.. code:: bash

    ~/CppTemplate$ ./tools/build.sh

------------
Manual Build
------------

.. code:: bash

    ~/CppTemplate$ mkdir build
    ~/CppTemplate$ cd build/
    ~/CppTemplate/build$ cmake ..
    ~/CppTemplate/build$ make
    ~/CppTemplate/build$ make run_unit_tests
    ~/CppTemplate/build$ sudo make install