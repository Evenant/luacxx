/**
 * @file table_tables.cpp
 * @author scongebop (littlefast2@gmail.com)
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 * @brief 
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

#define Lua this->state->state

LuaTable table::new_table(const char* field, int field_count)
{
	int t = this->get_table_from_path(); printf("get_table_from_path\n");
	lua_createtable(Lua, 0, field_count); printf("createtable\n");
	lua_setfield(Lua, -2, field); printf("setfield\n");
	this->set_table_from_path(); printf("set_table_from_path\n");
	return this->get_table(field);
}

LuaTable table::get_table(const char* field)
{
	LuaTable t(new table(this->path));
	/*
	for (auto i = this->path.begin();i != this->path.end();++i)
		t->path.push_back(*i);
	*/
	t->path.push_back(field);
	return t;
}

void table::clone_from(std::shared_ptr<table> from)
{
	std::vector<const char *> vc = from->get_all_fields();
	for (auto i = vc.cbegin();i!= vc.cend();++i)
	{
		if (from->is_nil(*i)) continue;

		else if (from->is_boolean(*i)) 
			this->set_boolean(*i,
				from->get_boolean(*i));

		else if (from->is_number(*i)) 
			this->set_number(*i,
				from->get_number(*i));

		else if (from->is_string(*i))
			this->set_string(*i,
				from->get_string(*i));
		
		else if (from->is_table(*i))
		{
			LuaTable new_table = this->new_table(*i, from->maxlength());
			new_table->clone_from(from->get_table(*i));
		}
	}
}

bool table::is_table(const char* field)
{
	int t = this->get_table_from_path();
	lua_getfield(Lua, t, field);
	bool b = (bool)lua_istable(Lua, -1);
	lua_settop(Lua, 0);
	return b;
}

