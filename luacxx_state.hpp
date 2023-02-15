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
#include <memory>

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

		/**
		 * @brief Returns handle to the global table (or the _G table).
		 * 
		 * @return table 
		 */
		std::shared_ptr<table> global_table();

        void dofile(const char* filename);
		void dostring(const char* str);

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

		/**
		 * state_stdlib.cpp
		 */
		
		/**
		 * @brief Opens Base Library.
		 */
		void openlib_base();

		/**
		 * @brief Opens Table Library. (required for using `global_table()`)
		 */
		void openlib_table();

		/**
		 * @brief Opens IO Library.
		 */
		void openlib_io();

		/**
		 * @brief Opens OS Library.
		 */
		void openlib_os();

		/**
		 * @brief Opens String Library.
		 */
		void openlib_string();

		/**
		 * @brief Opens Math Library.
		 */
		void openlib_math();

		/**
		 * @brief Opens Debug Library.
		 */
		void openlib_debug();

		/**
		 * @brief Opens Package Library.
		 */
		void openlib_package();

		#ifdef LUACXX_LUAJIT
		// TODO: Put stuff for LuaJIT here.
		#endif

		/**
		 * @brief Runs every other `openlib_*`
		 */
		void openlib_all();
	};
}

#endif