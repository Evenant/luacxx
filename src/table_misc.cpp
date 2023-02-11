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

#include "lua.h"
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
	for (auto i = this->path.begin();i != this->path.end();++i)
		lua_setfield(Lua, -1, *i);
	return lua_gettop(Lua);
}


