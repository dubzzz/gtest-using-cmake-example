# Google Test using CMake -- example [![Build Status](https://travis-ci.org/dubzzz/gtest-using-cmake-example.svg?branch=master)](https://travis-ci.org/dubzzz/gtest-using-cmake-example)[![Build status](https://ci.appveyor.com/api/projects/status/c84nnf4o27a7jsjf/branch/master?svg=true)](https://ci.appveyor.com/project/dubzzz/gtest-using-cmake-example/branch/master)

This repository provides a very simple example of how defining a CMakeLists.txt in order to run unit-tests using Google Test framework.

The build system cross-platform (GNU/linux, Windows) and cross-compilers (clang, g++ and visual studio) is also considered.
- .travis.yml: configuration to build such projects on Unix-based platforms with clang or g++.
- appveyor.yml: configuration to build such projects on Windows platforms using Visual Studio compiler 
