# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)

set(_MAJOR_VERSION "1")
set(EXE_MINOR_VERSION "1")
set(EXE_PATCH_VERSION "0")
set(EXE_VERSION_STRING "${EXE_MAJOR_VERSION}.${EXE_MINOR_VERSION}.${EXE_PATCH_VERSION}")

if (CMAKE_VERSION VERSION_LESS 3.0)
  project (LinkList)
  set(PROJECT_VERSION_MAJOR "${EXE_MAJOR_VERSION}")
  set(PROJECT_VERSION_MINOR "${EXE_MINOR_VERSION}")
  set(PROJECT_VERSION_PATCH"${EXE_PATCH_VERSION}")
  set(PROJECT_VERSION "${EXE_VERSION_STRING}")
else()
  cmake_policy(SET CMP0048 NEW)
  project (LinkList VERSION "${EXE_VERSION_STRING}" LANGUAGES CXX)
endif()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (Node)
add_subdirectory (example)
