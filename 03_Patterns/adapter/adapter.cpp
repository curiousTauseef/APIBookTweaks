/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   adapter.cpp
/// \author Martin Reddy
/// \brief  An example of the Adapter design pattern.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

/**
 2/8/17 -- Tal
 -- replaced std::endl with NewLine (NL) char.
   Generally it is inefficent to be flushing the buffer, unless you need to.
   see Tweak_Explainations.md (https://github.com/tlanc007/APIBookTweaks/blob/master/Tweak_Explainations.md#endl)
 -- using unique_ptr for Object
   removing need for explicit new/delete
   see Tweak_Explainations.md (https://github.com/tlanc007/APIBookTweaks/blob/master/Tweak_Explainations.md#smartpointers)

**/

#include <iostream>

#include "adapter.h"
#include "original.h"

using std::cout;
constexpr char NL {'\n'};


Adapter::Adapter()
: mOrig {std::make_unique<Original>() }
{
	cout << "Allocated new Original object inside Adapter" << NL;
}

Adapter::~Adapter()
{
	cout << "Destroyed Original object inside Adapter" << NL;
}

bool Adapter::DoSomething(int value)
{
	cout << "About to call Original::DoOperation from Adapter::DoSomething" << NL;
	mOrig->DoOperation(value, true);
	return true;
}

