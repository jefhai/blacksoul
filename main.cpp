/*
	BlackSoul - Created by Jeffrey Haines
 */

#include "engine.h"

#include <stdio.h>
#include <memory>
#include <exception>
 
int main(int argc, char **argv)
{
	std::unique_ptr<BLACKSOUL::Engine> engine;

	int ret = 0;
	try 
	{
        engine.reset(new BLACKSOUL::Engine());

		ret = engine->go();
	}
	catch (std::exception &e)
    {
    	ret = -1;
    }

	return ret;
}
