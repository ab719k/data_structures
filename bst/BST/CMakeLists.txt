set(CMAKE_BUILD_TYPE Debug)
# Create a library called "BST" which includes the source file "bst.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (BST bst.cpp)

target_compile_definitions(BST PUBLIC DBG_PRINT=0 DEBUG_FLAG=0)


# Make sure the compiler can find include files for our BST library
# when other libraries or executables link to BST
target_include_directories (BST PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
