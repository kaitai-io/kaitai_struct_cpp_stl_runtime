project (unittest CXX)

find_package(GTest REQUIRED)

add_executable(unittest unittest.cpp)

include(../Common.cmake)

target_include_directories(unittest PRIVATE ${CMAKE_SOURCE_DIR})

target_compile_options(unittest PRIVATE
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:
        # At the time of writing, we use a variadic `SETUP_STREAM(...)` macro everywhere
        # in `unittest.cpp`. However, variadic macros are only available since C++11, so
        # the `#define SETUP_STREAM(...)` line raises a warning `anonymous variadic macros
        # were introduced in C++11` when compiling with `-std=c++98`. Since we also use
        # `-Werror`, this warning turns into an error and blocks compilation. Therefore,
        # we change this specific diagnostic back to a non-fatal warning.
        -Wno-error=variadic-macros
    >
    $<$<CXX_COMPILER_ID:AppleClang,Clang>:
        # GoogleTest 1.8.1 (the last version supporting C++98) uses C++11 constructs in
        # its headers (e.g. trailing commas in enumerator lists), which Clang warns about
        # when compiling with `-std=c++98`. With `-Werror`, this becomes a build failure.
        # Demote it to a non-fatal warning so that we can still test the C++98 build.
        -Wno-error=c++11-extensions
    >
)

# Link the test executable with the main library and the test framework/library
target_link_libraries(unittest PRIVATE kaitai_struct_cpp_stl_runtime GTest::GTest GTest::Main)

add_test(NAME unittest COMMAND unittest)
