# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Heart_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Heart_autogen.dir\\ParseCache.txt"
  "Heart_autogen"
  )
endif()
