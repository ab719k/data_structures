# Add executable called "treeDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable (treeDemo tree_demo.cpp)
target_compile_definitions(treeDemo PRIVATE DBG_PRINT=0 DEBUG_FLAG=0)



# Link the executable to the Tree library. Since the Tree library has
# public include directories we will use those link directories when building
# treeDemo
target_link_libraries (treeDemo LINK_PUBLIC Tree)
