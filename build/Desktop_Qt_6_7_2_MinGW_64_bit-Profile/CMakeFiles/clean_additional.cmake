# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\MemoPad_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MemoPad_autogen.dir\\ParseCache.txt"
  "MemoPad_autogen"
  )
endif()
