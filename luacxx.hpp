/**
 * @file luacxx.hpp
 * @author scongebop (littlefast2@gmail.com)
 * @version 0.1
 * @date 2023-02-10
 * 
 * @copyright Copyright (c) 2023
 * 
 * @brief 
 */

#ifndef LUACXX_HPP
#define LUACXX_HPP

namespace luacxx
{
	// LUACXX_SRC is a definition that tells this header file that the source file including it is part
	// of LuaCXX, and thus will include Lua headers.

	#ifdef LUACXX_SRC

	extern "C"
	{
		#include "lua.h"
		#include "lualib.h"
		#include "lauxlib.h"
	}

	#else

	typedef struct lua_State lua_State;

	#endif
	
	class lua
	{
		private:
		/**
		 * @brief If this Lua object is initialized from another `lua_State`, this Lua object will not call `lua_close` on the `lua_State` when deconstructed.
		 */
		bool is_from_raw_state = false;

		#ifdef LUACXX_SRC

		public:
		lua_State* state = 0;

		#else

		private:
		lua_State* state = 0;

		#endif
		public:

		/**
		 * @brief Create a new Lua object
		 * @details description
		 */
		lua();

		/**
		 * @brief Construct a new Lua object from a raw `lua_State`
		 * 
		 * @param L 
		 */
		lua(lua_State* L);

		~lua();
	};
	
	class table
	{

	};
}

#endif