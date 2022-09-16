# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)

set(LIB_MAJOR_VERSION "1")
set(LIB_MINOR_VERSION "1")
set(LIB_PATCH_VERSION "0")
set(LIB_VERSION_STRING "${LIB_MAJOR_VERSION}.${LIB_MINOR_VERSION}.${LIB_PATCH_VERSION}")

if (CMAKE_VERSION VERSION_LESS 3.0)
  project (HELLO)
  set(PROJECT_VERSION_MAJOR "${LIB_MAJOR_VERSION}")
  set(PROJECT_VERSION_MINOR "${LIB_MINOR_VERSION}")
  set(PROJECT_VERSION_PATCH"${LIB_PATCH_VERSION}")
  set(PROJECT_VERSION "${LIB_VERSION_STRING}")
else()
  cmake_policy(SET CMP0048 NEW)
  project (HELLO VERSION "${LIB_VERSION_STRING}" LANGUAGES CXX)
endif()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_compile_definitions(DBG_PRINT=0)
#add_compile_definitions(OPENCV_VERSION=${OpenCV_VERSION})

# Recurse into the "BST" and "BSTDemo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (BST)
add_subdirectory (BSTDemo)
