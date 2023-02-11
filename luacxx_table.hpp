/**
 * @file luacxx_table.hpp
 * @author scongebop (littlefast2@gmail.com)
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @brief Contains `table`, used for interacting with internal Lua values from tables.
 */

#ifndef LUACXX_TABLE_HPP
#define LUACXX_TABLE_HPP

#include "luacxx_defs.hpp"

#include <vector>

namespace luacxx
{
	class table
	{
		private:
		/**
		 * @brief Get this table from the global table.
		 * 
		 * @return int
		 * Where this table is on the stack.
		 */
		int get_table_from_path(); // table_misc.cpp

		/**
		 * @brief The path to this table from the global table. ( if empty, then this is the global table )
		 */
		std::vector<const char*> path;
		lua *state = 0;

		public:
		/**
		 * table_misc.cpp
		 */
		
		/**
		 * @brief Get all fields
		 * 
		 * @return std::vector<const char*> 
		 */
		std::vector<const char*> get_all_fields();

		/**
		 * table_number.cpp
		 */

		/**
		 * @brief Set the number object
		 * 
		 * @param field 
		 * @param value 
		 */
		void set_number(const char* field, double value);
		double get_number(const char* field);
		bool is_number(const char* field);

		/**
		 * table_boolean.cpp
		 */

		/**
		 * @brief Set the boolean object
		 * 
		 * @param field 
		 * @param value 
		 */
		void set_boolean(const char* field, bool value);
		bool get_boolean(const char* field);
		bool is_boolean(const char* field);

        /**
         * table_string.cpp
         */

		/**
		 * @brief Set the string object
		 * 
		 * @param field 
		 * @param value 
		 */
		void set_string(const char* field, const char* value);
		const char* get_string(const char* field);
		bool is_string(const char* field);

        /**
         * table_nil.cpp
         */	

		/**
		 * @brief 
		 * 
		 * @param field 
		 * @return true 
		 * @return false 
		 */
		bool is_nil(const char* field);
		void nillify(const char* field);
		void nillify_all();

		table new_table(const char* field, int field_count);
		table get_table(const char* field);
		void clone_from(table from);
	};
}

#endif