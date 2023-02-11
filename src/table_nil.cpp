/**
 * @file table_nil.cpp
 * @author scongebop (littlefast2@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "lua.h"
#define LUACXX_SRC
extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include "luacxx.hpp"

using namespace luacxx;

#define Lua this->state->state

bool table::is_nil(const char* field)
{
	int t = this->get_table_from_path();
	lua_getfield(Lua, t, field);
	bool n = (bool)lua_isnil(Lua, t+1);
	lua_settop(Lua, 0);
	return n;
}

void table::nillify(const char *field)
{
	int t = this->get_table_from_path();
	lua_pushnil(Lua);
	lua_setfield(Lua, t, field);
	lua_settop(Lua, 0);
}

void table::nillify_all()
{
	
}
