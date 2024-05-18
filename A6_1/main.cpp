#include <iostream>
#include "SystemController.h"
#include "functions.h"



int main(int argc ,char *argv[])
{
	SystemController engine = SystemController();

	engine.Read_Majors(argv[1]);
	engine.Read_Units(argv[2]);
	engine.Read_Users(argv[3]);
	engine.Read_Users(argv[4]);


	Command_Operator(engine);

	return 0;
}