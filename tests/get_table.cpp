#include "luacxx.hpp"
#include "luacxx_state.hpp"

using namespace luacxx;

extern "C"
{
	#include <stdio.h>
	#include "string.h"
}

#include <memory>

int main()
{
	printf("Test: Getting values from a table\n");
	std::unique_ptr<lua> L(new lua());
	L -> openlib_all();
	std::unique_ptr<table> globals = L -> global_table();

	globals -> set_string("my_str", "Hello World");
	const char* x = globals -> get_string("my_str");
	
	printf("the variable `my_str` has a string value of: \"%s\"\n", x);
	if (strcmp(x, "Hello World")==0)
	{
		return 0;
	}else{
		return 1;
	}
}