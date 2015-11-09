#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Steering7" for configuration "Release"
set_property(TARGET Steering7 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Steering7 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/components/lib/Steering7.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "RTC111_vc10;coil111_vc10;omniORB417_rt;omniDynamic417_rt;omnithread34_rt;advapi32;ws2_32;mswsock"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/components/bin/Steering7.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Steering7 )
list(APPEND _IMPORT_CHECK_FILES_FOR_Steering7 "${_IMPORT_PREFIX}/components/lib/Steering7.lib" "${_IMPORT_PREFIX}/components/bin/Steering7.dll" )

# Import target "Steering7Comp" for configuration "Release"
set_property(TARGET Steering7Comp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Steering7Comp PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/components/bin/Steering7Comp.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS Steering7Comp )
list(APPEND _IMPORT_CHECK_FILES_FOR_Steering7Comp "${_IMPORT_PREFIX}/components/bin/Steering7Comp.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
