# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (cbuf SHARED cbuf.c)

SET_TARGET_PROPERTIES(cbuf PROPERTIES LINKER_LANGUAGE C )

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (cbuf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
