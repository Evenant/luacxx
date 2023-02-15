/**
 * @file table_misc.cpp
 * @author scongebop (littlefast2@gmail.com)
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @brief Miscellaneous methods ( methods that cannot be put into specific categories )
 */

#define LUACXX_SRC
extern "C"
{
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}
#include "luacxx.hpp"

#define Lua this->state->state

using namespace luacxx;

int table::get_table_from_path()
{
	lua_getglobal(Lua,"_G");
	for (auto i = this->path.cbegin();i != this->path.cend();++i)
		lua_getfield(Lua, -1, *i);
	return lua_gettop(Lua);
}

void table::set_table_from_path()
{
	for (auto i = this->path.cbegin();i != this->path.cend();++i)
		lua_setfield(Lua, -2, *i);
	lua_setglobal(Lua, "_G");
	
}

std::vector<const char*> table::get_all_fields()
{
	int t = this->get_table_from_path();
	std::vector<const char*> vs;
	
	lua_pushnil(Lua);
	while ( lua_next(Lua, t) != 0 )
	{
		// index -2 is key
		// index -1 is value

		if ( lua_isstring(Lua, -2) )
			vs.push_back(lua_tostring(Lua, -2));

		lua_pop(Lua, 1);
	}

	lua_settop(Lua, 0);
	return vs;
}

int table::maxlength()
{
	this->get_table_from_path();
	int i = (int)lua_objlen(Lua, -1);
	lua_settop(Lua, 0);
	return i;

}
