#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Steering7" for configuration "Debug"
set_property(TARGET Steering7 APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Steering7 PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/components/lib/Steering7.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "RTC111_vc10d;coil111_vc10d;omniORB417_rtd;omniDynamic417_rtd;omnithread34_rtd;advapi32;ws2_32;mswsock"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/components/bin/Steering7.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Steering7 )
list(APPEND _IMPORT_CHECK_FILES_FOR_Steering7 "${_IMPORT_PREFIX}/components/lib/Steering7.lib" "${_IMPORT_PREFIX}/components/bin/Steering7.dll" )

# Import target "Steering7Comp" for configuration "Debug"
set_property(TARGET Steering7Comp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Steering7Comp PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/components/bin/Steering7Comp.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS Steering7Comp )
list(APPEND _IMPORT_CHECK_FILES_FOR_Steering7Comp "${_IMPORT_PREFIX}/components/bin/Steering7Comp.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
