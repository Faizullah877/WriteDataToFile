# CMakeList.txt : CMake project for write_file, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (write_file "write_file.cpp" "write_file.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET write_file PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
