/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  ModuleB calls an instance method on ModuleA.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

/**
 More modern compilers will automatically dereference function pointers.
 -See moduleb.cpp
 -switched to "using" rather than typedef
 -switched to brace-init-list: see Tweak_Explainations.md
 -nullptr from NULL
 **/

#include "modulea.h"
#include "moduleb.h"

int main(int, char **)
{
    apibook::ModuleB b {};
    apibook::ModuleA a {};
    int closure {42};

	// add a callback for ModuleA to ModuleB
	b.SetCallback (&a, apibook::ModuleA::StaticWrapper, &closure);
	// tell ModuleB to invoke all its callbacks
	b.DoAction ();

	return 0;
}
