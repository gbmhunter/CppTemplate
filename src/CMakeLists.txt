

file(GLOB_RECURSE CppTemplate_SRC
        "*.cpp")

file(GLOB_RECURSE CppTemplate_HEADERS
        "${CMAKE_SOURCE_DIR}/include/*.hpp")

add_library(CppTemplate ${CppTemplate_SRC} ${CppTemplate_HEADERS})

if (COVERAGE)
    message("COVERAGE=TRUE, coverage will be enabled.")
#    set(CMAKE_CXX_FLAGS "-g -O0 -coverage ${CMAKE_CXX_FLAGS}")
#    set(CMAKE_EXE_LINKER_FLAGS "-coverage -lgcov ${CMAKE_EXE_LINKER_FLAGS}")
    target_compile_options(CppTemplate PUBLIC "-coverage")
    set_target_properties(CppTemplate PROPERTIES LINK_FLAGS "-coverage -lgcov")
else ()
    message("COVERAGE=FALSE, coverage will NOT be enabled.")
endif ()


target_include_directories(CppTemplate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# On Linux, "sudo make install" will typically copy the library
# into the folder /usr/local/bin
install(TARGETS CppTemplate DESTINATION lib)

# On Linux, "sudo make install" will typically copy the
# folder into /usr/local/include
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/CppTemplate DESTINATION include)