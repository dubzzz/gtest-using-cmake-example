# Google Test using CMake -- example [![Build Status](https://travis-ci.org/dubzzz/gtest-using-cmake-example.svg?branch=master)](https://travis-ci.org/dubzzz/gtest-using-cmake-example)[![Build status](https://ci.appveyor.com/api/projects/status/c84nnf4o27a7jsjf/branch/master?svg=true)](https://ci.appveyor.com/project/dubzzz/gtest-using-cmake-example/branch/master)

This repository provides a very simple example of how defining a CMakeLists.txt in order to run unit-tests using Google Test framework.

The build system cross-platform (GNU/linux, Windows) and cross-compilers (clang, g++ and visual studio) is also considered.
- .travis.yml: configuration to build such projects on Unix-based platforms with clang or g++.
- appveyor.yml: configuration to build such projects on Windows platforms using Visual Studio compiler 

## Compiling and linking against Google Test under Windows

As stated on Google Test official repository, at https://github.com/google/googletest/blob/master/googletest/README.md, `gtest-md.sln` solution build the dynamic version of GTest while the other is to consider for a static linkage.

> The msvc\ folder contains two solutions with Visual C++ projects. Open the gtest.sln or gtest-md.sln file using Visual Studio, and you are ready to build Google Test the same way you build any Visual Studio project. Files that have names ending with -md use DLL versions of Microsoft runtime libraries (the /MD or the /MDd compiler option). Files without that suffix use static versions of the runtime libraries (the /MT or the /MTd option). Please note that one must use the same option to compile both gtest and the test code. If you use Visual Studio 2005 or above, we recommend the -md version as /MD is the default for new projects in these versions of Visual Studio.
