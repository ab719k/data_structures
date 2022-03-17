# Create a library called "Tree" which includes the source file "tree.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (Tree tree.cpp)

# Make sure the compiler can find include files for our Tree library
# when other libraries or executables link to Tree
target_include_directories (Tree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
