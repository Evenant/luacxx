# LuaCXX

LuaCXX works on top of the raw Lua C API to make it easier for you to use Lua from C++.
LuaCXX is also made to work with LuaJIT.

# Building
Use `make` and list a pre-compiled Lua archive and a directory containing Lua headers.
```
make LIBLUA=/path/to/luastatic INCLUA=/path/to/lua/includes
```

The above will only build the static library, `make all` will build LuaCXX, build and run test programs, document the LuaCXX headers and put the static library, headers and documentation into a `luacxx.tar.gz` archive.
```
make all LIBLUA=/path/to/luastatic INCLUA=/path/to/lua/includes
```


