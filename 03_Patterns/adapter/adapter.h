/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   adapter.h
/// \author Martin Reddy
/// \brief  An example of the Adapter design pattern.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

/**
 2/8/17 -- Tal
 -- switched to =delete to disable copying
   instead of making them private
   see Tweak_Explainations.md (https://github.com/tlanc007/APIBookTweaks/blob/master/Tweak_Explainations.md#equalsdelete)
 -- using unique_ptr for Object
   removing need for explicit new/delete
   see Tweak_Explainations.md (https://github.com/tlanc007/APIBookTweaks/blob/master/Tweak_Explainations.md#smartpointers)
 **/

#ifndef ADAPTER_H
#define ADAPTER_H

#include <memory>

// forward declaration for the object wrapped by Adapter
class Original;

///
/// An Adapter that wraps access to an Original object.
///
class Adapter
{
public:
	Adapter();
    // prevent copying of this class because we have a pointer data member
    Adapter(const Adapter &) = delete;
    Adapter &operator =(const Adapter &) = delete;
	~Adapter();
    

	/// Call through to Original::DoSomething()
	bool DoSomething(int value);

private:

    std::unique_ptr<Original> mOrig;
};

#endif
