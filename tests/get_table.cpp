#include "luacxx.hpp"

using namespace luacxx;

extern "C"
{
	#include <stdio.h>
	#include "string.h"
}

#include <memory>

void car_analyze(LuaTable cartable);

int main()
{
	printf("Test: Getting values from a table\n");
	Lua L(new lua());
	L -> openlib_all();
	LuaTable globals = L -> global_table();

	globals -> set_string("my_str", "Hello World");
	const char* x = globals -> get_string("my_str");
	
	printf("The variable `my_str` has a string value of: \"%s\"\n", x);
	if (strcmp(x, "Hello World")!=0)
	{
		printf("Test failed: variable `my_str` does not have a string value of \"Hello World\"\n");
		return 1;
	}

	globals -> set_number("my_num", 25.0);

	if (!globals->is_number("my_num"))
	{
		printf("Test failed: variable `my_num` is not a number\n");
		return 1;
    }
	printf("my_num is a number\nand has a value of: %f\n", globals -> get_number("my_num"));
	
	printf("Wait a sec, Im assembling a car...\n");
	LuaTable car = globals->new_table("car1", 3);
	
	printf("Getting ready for wheels...\n");

	// Something happens here where it throws a segfault.
	LuaTable car_wheels = car -> new_table("wheels", 4);

	printf("Assembling some car wheels\n");

	car_wheels -> set_number("wheel1", 100.0);
	car_wheels -> set_number("wheel2", 90.0);
	car_wheels -> set_number("wheel3", 92.0);
	car_wheels -> set_number("wheel4", 99.0);

	printf("Done assembling car wheels\n");

	car -> set_string("model", "Ford");
	printf("Have set the model...\n");

	car -> set_boolean("can_drive", true);
	printf("Making car driveable...\n");

	printf("Alright Im done, now let me show you stuff about it.\n");

	car_analyze(car);

	
	return 0;
}

void car_analyze(LuaTable cartable)
{
	printf("Lets take a look at the wheels...\n");
	LuaTable car_wheels = cartable -> get_table("wheels");
	auto vc = car_wheels->get_all_fields();
	for (auto i = vc.begin();i != vc.end();++i)
	{
		printf("%s : %f\n",*i, car_wheels->get_number(*i));
    }

	printf("This car's model is: %s\n", cartable -> get_string("model"));
	if (cartable->get_boolean("can_drive")){
		printf("Yes this car can drive\n");
	}else{
		printf("Unfortunately, this car cannot drive\n");
	}

}