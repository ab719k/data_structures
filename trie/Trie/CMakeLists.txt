# Create a library called "Trie" which includes the source file "trie.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (Trie trie.cpp)

# Make sure the compiler can find include files for our Trie library
# when other libraries or executables link to Trie
target_include_directories (Trie PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
