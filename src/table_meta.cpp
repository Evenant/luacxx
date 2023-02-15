/**
 * @file table_meta.cpp
 * @author scongebop (littlefast2@gmail.com)
 * @version 0.1
 * @date 2023-02-15
 * 
 * @copyright Copyright (c) 2023
 * 
 * @brief for special methods in `table` like the constructor or destructor.
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

table::table(std::vector<const char*> frompath)
{
	this->path = frompath;
}
