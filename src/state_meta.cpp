/**
 * @file state_meta.cpp
 * @author scongebop (littlefast2@gmail.com)
 * @version 0.1
 * @date 2023-02-10
 * 
 * @copyright Copyright (c) 2023
 * 
 * @brief Definitions for special methods like the constructor and destructor.
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

lua::lua()
{
	this->state = luaL_newstate();
	this->is_from_raw_state = false;
	printf("Created Lua state\n");
}

lua::lua(lua_State* L)
{
	this->state = L;
	this->is_from_raw_state = true;
	printf("Created Lua state from raw `lua_State`\n");
}

lua::~lua()
{
	if (!this->is_from_raw_state)
		lua_close(this->state);
	printf("Destroyed Lua state\n");
}
