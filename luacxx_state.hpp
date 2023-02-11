/**
 * @file luacxx_state.hpp
 * @author scongebop (littlefast2@gmail.com)
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @brief Contains class `lua`, a class for interacting with a `lua_State`.
 */

#ifndef LUACXX_STATE_HPP
#define LUACXX_STATE_HPP

#include "luacxx_defs.hpp"

#ifndef LUACXX_SRC
typedef struct lua_State lua_State;
#endif

namespace luacxx
{
	class lua
	{
		private:
		/**
		* @brief If this Lua object is initialized from another `lua_State`, this Lua object will not call `lua_close` on the `lua_State` when deconstructed.
		*/
		bool is_from_raw_state = false;

		// If in a source file, the raw Lua state is exposed.
		#ifdef LUACXX_SRC
		public:
		lua_State* state = 0;
		#endif
		public:

		/**
		 * state_misc.cpp
		 */
		
		#ifdef LUACXX_SRC
		
		#endif

		/**
		 * state_meta.cpp
		 */

		/**
		 * @brief Create a new Lua object
		 */
		lua();
		/**
		 * @brief Construct a new Lua object from a raw `lua_State`
		 * 
		 * @param L 
		 */
		lua(lua_State* L);
		~lua();
		table global();

		/**
		 * state_stdlib.cpp
		 */
		void openlib_base();
		void openlib_table();
		void openlib_io();
		void openlib_os();
		void openlib_string();
		void openlib_math();
		void openlib_debug();
		void openlib_package();

		#ifdef LUACXX_LUAJIT
		// TODO: Put stuff for LuaJIT here.
		#endif

		void openlib_all();
	};
}

#endif