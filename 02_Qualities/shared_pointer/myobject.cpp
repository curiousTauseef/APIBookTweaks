/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   myobject.cpp
/// \author Martin Reddy
/// \brief  A simple class to demonstrate shared pointers.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

/**
 12/30/16 -- Tal
 I opted for:
 -std::shared_ptr instead of boost
 -using make_shared instead of new: see Tweak_Explainations.md (https://github.com/tlanc007/APIBookTweaks/blob/master/Tweak_Explainations.md#makeshared)
 -using "using" rather than typedef: see Tweak_Explainations.md (https://github.com/tlanc007/APIBookTweaks/blob/master/Tweak_Explainations.md#using)

 **/

#include <iostream>
#include "myobject.h"

namespace apibook {
    
MyObject::MyObject(const PrivateCtor& pctor, int id) :
mID(id)
{
    std::cout << "... created object (with key)" << mID << "\n";
}

MyObject::~MyObject()
{
    std::cout << "... destroyed object " << mID << "\n";
}

MyObjectPtr MyObject::CreateInstance(int id)
{
    return std::make_shared<MyObject> (MyObject::PrivateCtor {}, id);
}

}

