/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   original.cpp
/// \author Martin Reddy
/// \brief  An original class to be wrapped by an Adapter.
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

 **/

#include <iostream>

#include "original.h"

using std::cout;
constexpr char NL {'\n'};

void Original::DoOperation(int value, bool extra_arg)
{
	cout << "In Original::DoSomething with value " << value;
	cout << " and flag " << extra_arg << NL;
}
