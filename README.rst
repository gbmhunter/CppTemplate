===========
CppTemplate
===========

-----------------------------------------------------------------------------------------
A template repository to quick-start C++ development.
-----------------------------------------------------------------------------------------

.. image:: https://travis-ci.org/mbedded-ninja/CppTemplate.svg?branch=master
	:target: https://travis-ci.org/mbedded-ninja/CppTemplate

--------
Features
--------

- C++14 template/example project
- CMake-based build system
- Automatic build script in ./tools/
- gtest-based unit tests
- CI functionality using TravisCI
- Semantic versioning and keepachangelog.com-based Changelog format

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