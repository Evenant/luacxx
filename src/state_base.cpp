/**
 * @file state_base.cpp
 * @author scongebop (littlefast2@gmail.com)
 * @version 0.1
 * @date 2023-02-10
 * 
 * @copyright Copyright (c) 2023
 * 
 * @brief Method definitions for `lua::lua` for metamethods like the constructor and destructor.
 */


#define LUACXX_SRC
#include <luacxx.hpp>

using namespace luacxx;

lua::lua()
{
	int s = LUA_VERSION_NUM;
}

lua::lua(lua_State* L)
{

}

lua::~lua()
{

}
