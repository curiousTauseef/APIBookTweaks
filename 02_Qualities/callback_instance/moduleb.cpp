/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   moduleb.h
/// \author Martin Reddy
/// \brief  A module that invokes a callback on an object.
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

#include "moduleb.h"

namespace apibook {

ModuleB::ModuleB() :
    mObject {nullptr},
    mCallback {nullptr},
    mClosure {nullptr}
    { }

void ModuleB::SetCallback(void *obj, CallbackType cb, void *data)
{
    mObject = obj;
    mCallback = cb;
    mClosure = data;
}

void ModuleB::DoAction()
{
    if (mCallback)
    {
        // (*mCallback) (mObject, "Hello World", mClosure); // dereference ptr-2-function
        mCallback (mObject, "Hello World", mClosure);
    }
}

}
