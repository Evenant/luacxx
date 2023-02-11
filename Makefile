
CXX=g++
AR=ar
CXX_STD=gnu++14
CXXFLAGS=


default: build

build: her
	echo $^

doxy: docs/ doxy_serve

docs/: luacxx.hpp luacxx_defs.hpp \
	luacxx_state.hpp luacxx_table.hpp 
	doxygen .doxy

doxy_serve:
	cd docs/html && \
		python -m http.server
	
.PHONY: build default doxy