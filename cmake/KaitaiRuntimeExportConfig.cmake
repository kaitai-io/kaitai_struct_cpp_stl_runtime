include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/KaitaiRuntime)
set(KAITAI_TARGET_NAME KaitaiRuntime-targets)

#------------------------------------------------------------------------------
#
# Copy header and library

install (FILES ${HEADERS}
    DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/kaitai
    )

if (WIN32)
    install(TARGETS ${PROJECT_NAME}
        EXPORT ${KAITAI_TARGET_NAME}
        RUNTIME DESTINATION lib
            )
else()
    install(TARGETS ${PROJECT_NAME}
        EXPORT ${KAITAI_TARGET_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
endif()

#------------------------------------------------------------------------------
#
# Setup export name

install(EXPORT ${KAITAI_TARGET_NAME}
  FILE
    KaitaiRuntimeTargets.cmake
  NAMESPACE 
    Kaitai::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)

set_target_properties(${PROJECT_NAME} PROPERTIES EXPORT_NAME KaitaiRuntime)


#------------------------------------------------------------------------------
#
# Setup export name

include(CMakePackageConfigHelpers)

# It's used for portable purposes
export(EXPORT  ${KAITAI_TARGET_NAME}
    NAMESPACE Kaitai::
    FILE  ${CMAKE_CURRENT_BINARY_DIR}/KaitaiRuntimeTargets.cmake
    )

# Creates config file to be found by `find_package`
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/KaitaiRuntimeConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/KaitaiRuntimeConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

# Configure custom module to be used by the config file
configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/FindIconv.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/FindIconv.cmake
    COPYONLY
    )

install(FILES
    ${CMAKE_CURRENT_LIST_DIR}/FindIconv.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/KaitaiRuntimeConfig.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)


export(PACKAGE KAITAI_RUNTIME)