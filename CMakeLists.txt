cmake_minimum_required(VERSION 3.1.0)
project(CppTemplate)

# Custom CMake module path that is part if this repo
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

include(CodeCoverage)

add_definitions(-std=c++14)

option(BUILD_TESTS "If set to true, unit tests will be build as part of make all." TRUE)
if (BUILD_TESTS)
    message("BUILD_TESTS=TRUE, unit tests will be built.")
else ()
    message("BUILD_TESTS=FALSE, unit tests will NOT be built.")
endif ()

option(COVERAGE "If set to true, coverage will be enabled." FALSE)
#if (COVERAGE)
#    message("COVERAGE=TRUE, coverage will be enabled.")
#    set(CMAKE_CXX_FLAGS "-g -O0 -coverage ${CMAKE_CXX_FLAGS}")
#    set(CMAKE_EXE_LINKER_FLAGS "-coverage -lgcov ${CMAKE_EXE_LINKER_FLAGS}")
#else ()
#    message("COVERAGE=FALSE, coverage will NOT be enabled.")
#endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")

#=================================================================================================#
#========================================= gtest INSTALL =========================================#
#=================================================================================================#

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

#=================================================================================================#
#========================================= This Project ==========================================#
#=================================================================================================#

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate
include_directories(include)

add_subdirectory(src)
if(BUILD_TESTS)
    add_subdirectory(test/unit)
endif()
