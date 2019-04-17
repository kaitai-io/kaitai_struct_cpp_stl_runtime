project (kaitai_struct_cpp_stl_runtime CXX)
cmake_minimum_required (VERSION 3.3)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)


find_package(ZLIB)
find_package(Iconv)

set (HEADERS
    kaitai/kaitaistream.h
    kaitai/kaitaistruct.h
)

set (SOURCES
    kaitai/kaitaistream.cpp
)

set(STRING_ENCODING_TYPE "ICONV" CACHE STRING "Set the way strings have to be encoded (ICONV|NONE|...)")

add_library (${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} 
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/kaitai>
    )


if (ZLIB_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE ZLIB::ZLIB)
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DKS_ZLIB)
endif()
if(Iconv_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE Iconv::Iconv)
 endif()

if (STRING_ENCODING_TYPE STREQUAL "ICONV")
   target_compile_definitions(${PROJECT_NAME} PRIVATE -DKS_STR_ENCODING_ICONV)
elseif (STRING_ENCODING_TYPE STREQUAL "NONE")
   target_compile_definitions(${PROJECT_NAME} PRIVATE -DKS_STR_ENCODING_NONE)
else()
    # User action requested
endif()

include(cmake/KaitaiRuntimeExportConfig.cmake)
