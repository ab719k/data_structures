# Add executable called "trieDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable (trieDemo demo.cpp)


# Link the executable to the Trie library. Since the Trie library has
# public include directories we will use those link directories when building
# trieDemo
target_link_libraries (trieDemo LINK_PUBLIC Trie)
