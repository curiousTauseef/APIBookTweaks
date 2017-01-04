/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  An example using Boost shared pointers.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

/** 
 12/30/16 -- Tal
 I opted for:
 -std::shared_ptr instead of boost
 -using make_shared instead of new: see Tweak_Explainations.md
 -using "using" rather than typedef
 **/

#include <iostream>
#include "myobject.h"

int main(int argc, char *argv[])
{    
    std::cout << "> main()" << "\n";

	{
		apibook::MyObjectPtr ptr;

		// create a new instance of MyObject
        std::cout << "> CreateInstance(1)" << "\n";
		ptr = apibook::MyObject::CreateInstance(1);

		// create another instance of MyObject
        std::cout << "> CreateInstance(2)" << "\n";
		ptr = apibook::MyObject::CreateInstance(2);
	}
	// both instances get deleted when they go out of scope

    std::cout << "> exit()" << "\n";
}
