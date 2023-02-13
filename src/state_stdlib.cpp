/**
 * @file state_stdlib.cpp
 * @author scongebop (littlefast2@gmail.com)
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @brief Definitions related to opening the Lua standard library
 */

#define LUACXX_SRC
extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}
#include "luacxx.hpp"

using namespace luacxx;

#define openlib(L, name, libfunc) lua_pushcfunction(L, libfunc);lua_pushstring(L, name);lua_call(L, 1, 0)

void lua::openlib_base()
{
	openlib(this->state, "", luaopen_base);
}
void lua::openlib_table()
{
	openlib(this->state, LUA_TABLIBNAME, luaopen_table);
}
void lua::openlib_io()
{
	openlib(this->state, LUA_IOLIBNAME, luaopen_io);
}
void lua::openlib_os()
{
	openlib(this->state, LUA_OSLIBNAME, luaopen_os);
}
void lua::openlib_string()
{
	openlib(this->state, LUA_STRLIBNAME, luaopen_string);
}
void lua::openlib_math()
{
	openlib(this->state, LUA_MATHLIBNAME, luaopen_math);
}
void lua::openlib_debug()
{
	openlib(this->state, LUA_DBLIBNAME, luaopen_debug);
}
void lua::openlib_package()
{
	openlib(this->state, LUA_LOADLIBNAME, luaopen_package);
}

#ifdef LUACXX_LUAJIT
// TODO: Put stuff for LuaJIT here.
#endif

void lua::openlib_all()
{
	this->openlib_base();
	this->openlib_table();
	this->openlib_io();
	this->openlib_os();
	this->openlib_string();
    this->openlib_math();
	this->openlib_debug();
	this->openlib_package();
	#ifdef LUACXX_LUAJIT
	// TODO: Put stuff for LuaJIT here.
	#endif
}
