/**
 * @file table_string.cpp
 * @author scongebop (littlefast2@gmail.com)
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @brief 
 */

#define LUACXX_SRC
extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include "luacxx.hpp"

#define Lua this->state->state

using namespace luacxx;

void table::set_string(const char *field, const char *value)
{
	int t = this->get_table_from_path();
	lua_pushstring(Lua, value);
	lua_setfield(Lua, -2, field);
	this->set_table_from_path();
	lua_settop(Lua, 0);
}

const char *table::get_string(const char *field)
{
	int t = this->get_table_from_path();
	lua_getfield(Lua, -1, field);
	const char* b = lua_tostring(Lua, -1);
	lua_settop(Lua, 0);
	return b;
}

bool table::is_string(const char *field)
{
	int t = this->get_table_from_path();
	lua_getfield(Lua, t, field);
	bool b = (bool)lua_isstring(Lua, -1);
	lua_settop(Lua, 0);
	return b;
}
