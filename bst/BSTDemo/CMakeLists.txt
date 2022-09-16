set(CMAKE_BUILD_TYPE Debug)
# Add executable called "bstDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable (bstDemo bst_demo.cpp)
target_compile_definitions(bstDemo PRIVATE DBG_PRINT=0 DEBUG_FLAG=0)



# Link the executable to the BST library. Since the BST library has
# public include directories we will use those link directories when building
# bstDemo
target_link_libraries (bstDemo LINK_PUBLIC BST)
