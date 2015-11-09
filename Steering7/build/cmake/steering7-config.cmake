# Steering7 CMake config file
#
# This file sets the following variables:
# Steering7_FOUND - Always TRUE.
# Steering7_INCLUDE_DIRS - Directories containing the Steering7 include files.
# Steering7_IDL_DIRS - Directories containing the Steering7 IDL files.
# Steering7_LIBRARIES - Libraries needed to use Steering7.
# Steering7_DEFINITIONS - Compiler flags for Steering7.
# Steering7_VERSION - The version of Steering7 found.
# Steering7_VERSION_MAJOR - The major version of Steering7 found.
# Steering7_VERSION_MINOR - The minor version of Steering7 found.
# Steering7_VERSION_REVISION - The revision version of Steering7 found.
# Steering7_VERSION_CANDIDATE - The candidate version of Steering7 found.

message(STATUS "Found Steering7-1.0.0")
set(Steering7_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(Steering7_INCLUDE_DIRS
#    "C:/Program Files/Steering7/include/steering7-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(Steering7_IDL_DIRS
#    "C:/Program Files/Steering7/include/steering7-1/idl")
set(Steering7_INCLUDE_DIRS
    "C:/Program Files/Steering7/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(Steering7_IDL_DIRS
    "C:/Program Files/Steering7/include//idl")


if(WIN32)
    set(Steering7_LIBRARIES
        "C:/Program Files/Steering7/components/lib/steering7.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(Steering7_LIBRARIES
        "C:/Program Files/Steering7/components/lib/steering7.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(Steering7_DEFINITIONS ${<dependency>_DEFINITIONS})

set(Steering7_VERSION 1.0.0)
set(Steering7_VERSION_MAJOR 1)
set(Steering7_VERSION_MINOR 0)
set(Steering7_VERSION_REVISION 0)
set(Steering7_VERSION_CANDIDATE )

