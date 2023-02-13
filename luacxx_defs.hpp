/**
 * @file luacxx_defs.hpp
 * @author scongebop (littlefast2@gmail.com)
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @brief Typedef's and macros for internal use and vendoring.
 */

#ifndef LUACXX_DEFS_HPP
#define LUACXX_DEFS_HPP

#include <memory>

namespace luacxx
{
	typedef class table table;
	typedef class lua lua;

	/**
	 * @brief To create a new state: `Lua v(new lua)`
	 */
	typedef std::unique_ptr<lua> Lua;
	typedef std::unique_ptr<table> LuaTable;
	
	// LUACXX_SRC is a definition that tells this header file that the source file including it is part
	// of LuaCXX, and thus will include Lua headers.
}

#endif