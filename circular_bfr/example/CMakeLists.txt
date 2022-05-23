# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable (cbufDemo cbuf_ex.c)

SET_TARGET_PROPERTIES(cbufDemo PROPERTIES LINKER_LANGUAGE C )

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (cbufDemo LINK_PUBLIC cbuf)
