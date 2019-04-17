# find iconv header

find_package(PkgConfig)
pkg_check_modules(PC_Iconv QUIET Iconv)


set(Iconv_LIBRARIES_NAME libiconv libiconv-2)
if(UNIX)
	list(APPEND Iconv_LIBRARIES_NAME c)
endif()

find_path(Iconv_INCLUDE_DIR
	NAMES iconv.h
	PATHS ${PC_Iconv_INCLUDE_DIRS}
	)
find_library(Iconv_LIBRARY
	NAMES ${Iconv_LIBRARIES_NAME}
	)

mark_as_advanced(Iconv_FOUND Iconv_INCLUDE_DIR Iconv_LIBRARY)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Iconv
	REQUIRED_VARS Iconv_INCLUDE_DIR Iconv_LIBRARY
	)

if(Iconv_FOUND)
	set(Iconv_INCLUDE_DIRS "${Iconv_INCLUDE_DIR}")
	set(Iconv_LIBRARIES "${Iconv_LIBRARY}")
	if(NOT TARGET Iconv::Iconv)
		add_library(Iconv::Iconv INTERFACE IMPORTED)
	endif()
	set_property(TARGET Iconv::Iconv 
		PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Iconv_INCLUDE_DIRS})
	set_property(TARGET Iconv::Iconv
		PROPERTY INTERFACE_LINK_LIBRARIES ${Iconv_LIBRARIES})

endif(Iconv_FOUND)