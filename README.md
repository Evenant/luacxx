# LuaCXX

LuaCXX works on top of the raw Lua C API to make it easier for you to use Lua from C++.
LuaCXX is also made to work with LuaJIT.

**THIS PROJECT IS NOT READY FOR PRODUCTION, THERE IS STILL ALOT MORE OF LUA THAT IS NOT ACCESIBLE VIA THESE BINDINGS**

TODO:
- [x] Allow getting and setting values from global table.
- [ ] Allow getting values from nested tables. ( tables in tables )
- [ ] Allow getting, setting and running Functions and CFunctions.
- [ ] A class that is for creating parameters or return values for CFunctions.

# Building
Use `make` and list a pre-compiled Lua archive and a directory containing Lua headers.
```
make LIBLUA=/path/to/luastatic INCLUA=/path/to/lua/includes
```

The above will only build the static library, `make all` will build LuaCXX, build and run test programs, create documentation of LuaCXX using Doxygen and put the static library, headers and documentation into a `luacxx.tar.gz` archive. **REQUIRES YOU TO HAVE DOXYGEN INSTALLED**
```
make all LIBLUA=/path/to/luastatic INCLUA=/path/to/lua/includes
```

Using Python3 to view doxygen generated documentation. (You must run `make doxy` or `make all ...` first)
```
make doxy_view
```

# License
This project is licensed under [GNU Lesser General Public License v3](LICENSE.txt).
