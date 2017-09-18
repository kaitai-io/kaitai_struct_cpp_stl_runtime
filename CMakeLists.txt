project (kaitai_struct_cpp_stl_runtime CXX)
cmake_minimum_required (VERSION 3.3)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(ZLIB)

find_path(ICONV_INCLUDE_DIRS iconv.h)
mark_as_advanced(ICONV_INCLUDE_DIRS)
find_library(ICONV_LIBRARIES NAMES libiconv libiconv-2 c)
mark_as_advanced(ICONV_LIBRARIES)

set(ICONV_FOUND FALSE)
if(ICONV_INCLUDE_DIRS AND ICONV_LIBRARIES)
    SET(ICONV_FOUND TRUE)
endif()

set (HEADERS
    kaitai/kaitaistream.h
    kaitai/kaitaistruct.h
)

set (SOURCES
    kaitai/kaitaistream.cpp
)

option(USE_STRING_ENCODING "Decode strings via iconv" ON)

add_library (${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

if (ZLIB_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${ZLIB_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${ZLIB_LIBRARIES})
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DKS_ZLIB)
endif()

if(ICONV_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${ICONV_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${ICONV_LIBRARIES})
endif()

if (ICONV_FOUND AND USE_STRING_ENCODING)
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DKS_STR_ENCODING_ICONV)
elseif (NOT USE_STRING_ENCODING)
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DKS_STR_ENCODING_NONE)
else()
    # User action requested
endif()

if (WIN32)
    install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION lib)
else()
    install (TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib
    )
endif()
