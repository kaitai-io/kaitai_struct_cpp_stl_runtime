project("KatitaiCMakeBinding")

file(GLOB KaitaiBindingSrc
    "kaitai/*.h"
    "kaitai/*.cpp"
)

add_library(${PROJECT_NAME} STATIC ${KaitaiBindingSrc})
add_library(kaitai::kaitai ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/
)

target_compile_definitions(${PROJECT_NAME} 
    PRIVATE -DKS_STR_ENCODING_NONE
)

target_compile_definitions(${PROJECT_NAME} 
    PUBLIC -DNOMINMAX
)