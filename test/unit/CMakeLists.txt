#
# \file 	        CMakeLists.txt
# \author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
# \edited               n/a
# \created		2017-11-24
# \last-modified	2017-11-24
# \brief 		Contains instructions for building the unit tests.
# \details
#		See README.md in root dir for more info.

enable_testing()
find_package (Threads)
#find_package(GTest REQUIRED)
#message("gtest libraries found at ${GTEST_BOTH_LIBRARIES}")

file(GLOB_RECURSE CppTemplateTests_SRC
        "*.cpp"
        "*.hpp")


add_executable(CppTemplateTests ${CppTemplateTests_SRC})

if(COVERAGE)
    message("Coverage enabled.")
    target_compile_options(CppTemplateTests PRIVATE --coverage)
    target_link_libraries(CppTemplateTests PRIVATE --coverage)
endif()

target_link_libraries(CppTemplateTests LINK_PUBLIC CppTemplate gtest_main ${CMAKE_THREAD_LIBS_INIT})

# The custom target and custom command below allow the unit tests
# to be run.
# If you want them to run automatically by CMake, uncomment #ALL
add_custom_target(
        run_unit_tests #ALL
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/CppTemplateTests.touch CppTemplateTests)

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/CppTemplateTests.touch
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/CppTemplateTests)