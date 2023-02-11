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

namespace luacxx
{
	typedef class table table;
	typedef class lua lua;
	
	// LUACXX_SRC is a definition that tells this header file that the source file including it is part
	// of LuaCXX, and thus will include Lua headers.
}

#endif