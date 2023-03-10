# Path to a static Lua library.
# Example: /usr/lib/liblua.a
LIBLUA=

# Path to a directory containing Lua headers.
# Example: /usr/include/
INCLUA=

##########################################################################################
# THE 2 VARIABLES ABOVE ARE VERY IMPORTANT FOR ACTUALLY BUILDING/TESTING LuaCXX, 
##########################################################################################

# Standard compiler stuff
CXX=clang++
AR=llvm-ar
CXX_STD=gnu++14

# Where output files (libraries, headers and stuff) are put into when running `make pack`.
PACKDIR=./LuaCXX

# Extra flags to pass into the compiler.
MYCXXFLAGS=

# Extra flags to pass into the compiler when building the LuaCXX static library.
MYCXXFLAGS_BUILD=

# Extra flags to pass into the compiler when building LuaCXX tests.
MYCXXFLAGS_TEST=

# The name of the LuaCXX static library.
LIBRARY_OUT=libluacxx.a

##########################################################################################
#
#
# END OF USER VARIABLES
#
#
##########################################################################################

# Headers that expose the LuaCXX API.
HEADERS= \
	luacxx.hpp \
	luacxx_defs.hpp \
	luacxx_state.hpp \
	luacxx_table.hpp

LUACXX_STATE= \
	src/state_meta.o \
	src/state_misc.o \
	src/state_stdlib.o

LUACXX_TABLE= \
	src/table_boolean.o \
	src/table_meta.o \
	src/table_misc.o \
	src/table_nil.o \
	src/table_number.o \
	src/table_string.o \
	src/table_tables.o

LUACXX_ALL = ${LUACXX_STATE} ${LUACXX_TABLE}

LUACXX_TESTS= \
	tests/get_table

# By default, only build the project
default: build

all: build tests doxy pack

# Build and run tests
tests: tests_build tests_run

tests_build: ${LIBRARY_OUT} ${LUACXX_TESTS}

tests_run: tests_build
	$(foreach a, ${LUACXX_TESTS}, ${a} && ) echo "Tests run with no non-zero returns!"
	read v

# An alias
build: ${LIBRARY_OUT}

# Package the output files into a tuacxx.tar.gz archive.
pack: build tests doxy
	mkdir -p pack/include
	mkdir -p pack/lib
	mkdir -p pack/share/luacxx

	cp -t pack/include/ ${HEADERS}
	cp ${LIBRARY_OUT} pack/lib
	cp -r -t pack/share/luacxx docs/*

	tar -cf luacxx.tar pack/*
	gzip luacxx.tar
	rm -rf pack

# An alias
doxy: docs

# Build the documentation for the public API to LuaCXX
docs:
	doxygen .doxy

# Serve the documentation HTML files locally with python, you can then view it from the browser.
doxy_view:
	cd docs/html && \
		python3 -m http.server

clean:
	rm src/*.o
	rm ${LIBRARY_OUT}
	rm tests/*.o
	rm ${LUACXX_TESTS}
	rm -rf docs/
	rm luacxx.tar.gz

.PHONY: \
	default \
	all \
	tests build_tests run_tests \
	build \
	pack \
	doxy doxy_view \
	clean

# BUILDING LuaCXX AND TESTS

ifeq (${DYLIB},)

# Build LuaCXX as a static library
$(LIBRARY_OUT): ${LUACXX_ALL} ${HEADERS}
	${AR} -rc $(LIBRARY_OUT) ${LUACXX_ALL}
else

# Build LuaCXX as a dynamic library
$(LIBRARY_OUT): ${LUACXX_ALL} ${HEADERS}
	${CXX} -shared ${LUACXX_ALL} -o ${LIBRARY_OUT}
MYCXXFLAGS+= -fpic
endif
# luacxx_state

src/state_meta.o: src/state_meta.cpp
	$(cxx)
src/state_misc.o: src/state_misc.cpp
	$(cxx)
src/state_stdlib.o: src/state_stdlib.cpp
	$(cxx)

# luacxx_table

src/table_boolean.o: src/table_boolean.cpp
	$(cxx)

src/table_meta.o: src/table_meta.cpp
	${cxx}

src/table_misc.o: src/table_misc.cpp
	$(cxx)

src/table_nil.o: src/table_nil.cpp
	$(cxx)

src/table_number.o: src/table_number.cpp
	$(cxx)

src/table_string.o: src/table_string.cpp
	$(cxx)

src/table_tables.o: src/table_tables.cpp
	$(cxx)

# tests

tests/get_table: tests/get_table.o
	$(cxx_testprogram)
tests/get_table.o: tests/get_table.cpp
	$(cxx_test)



# For compiling LuaCXX source files
define cxx
${CXX} $^ -c \
	-I${PWD} \
	-I${INCLUA} \
	${MYCXXFLAGS} \
	${MYCXXFLAGS_BUILD} \
	-o $@
endef

# For compiling LuaCXX test source files
define cxx_test
${CXX} $^ -c \
	-I${PWD} \
	-I${INCLUA} \
	${MYCXXFLAGS} \
	${MYCXXFLAGS_TEST} \
	-o $@
endef

# For creating LuaCXX test programs
define cxx_testprogram
${CXX} $^ \
	${PWD}/${LIBRARY_OUT} \
	${LIBLUA} \
	-o $@
endef
