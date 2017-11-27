

file(GLOB_RECURSE CppTemplate_SRC
        "*.cpp")

file(GLOB_RECURSE CppTemplate_HEADERS
        "${CMAKE_SOURCE_DIR}/include/*.hpp")

add_library(CppTemplate ${CppTemplate_SRC} ${CppTemplate_HEADERS})

target_include_directories(CppTemplate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# On Linux, "sudo make install" will typically copy the library
# into the folder /usr/local/bin
install(TARGETS CppTemplate DESTINATION lib)

# On Linux, "sudo make install" will typically copy the
# folder into /usr/local/include
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/CppTemplate DESTINATION include)