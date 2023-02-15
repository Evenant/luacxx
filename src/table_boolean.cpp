/**
 * @file table_boolean.cpp
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

using namespace luacxx;

#define Lua this->state->state

void table::set_boolean(const char *field, bool value)
{
	int t = this->get_table_from_path();
	lua_pushboolean(Lua, value);
	lua_setfield(Lua, -2, field);
	this->set_table_from_path();
	lua_settop(Lua, 0);
}

bool table::get_boolean(const char* field)
{
	int t = this->get_table_from_path();
	lua_getfield(Lua, -1, field);
	bool b = (bool)lua_toboolean(Lua, -1);
	lua_settop(Lua, 0);
	return b;
}

bool table::is_boolean(const char *field)
{
	int t = this->get_table_from_path();
	lua_getfield(Lua, -1, field);
	bool b = (bool)lua_isboolean(Lua, -1);
	lua_settop(Lua, 0);
	return b;
}

