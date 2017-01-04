/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   myobject.h
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
 -using make_shared instead of new: see Tweak_Explainations.md
 -using "using" rather than typedef
 **/

#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <memory>

namespace apibook {

/// A reference-counted pointer to MyObject
using MyObjectPtr = std::shared_ptr<class MyObject>;
    
///
/// A class that lets you create reference-counted
/// pointers to itself via a factory method. The
/// constructor is declared to be private, so you
/// have to use CreateInstance() instead of new to
/// create instances of MyObject.
///
    
/**
   In order to use std::make_shared(), the constructor couldn't be private.
   Instead have an internal class with a private constructor.  This allows us to
   maintain the intent of the factory pattern and the use of make_shared.
 **/
class MyObject
{
public:
    /// Create a new (reference-counted) instance of MyObject
    static MyObjectPtr CreateInstance (int id);
    ~MyObject();

    class PrivateCtor {
    private:
        friend MyObjectPtr MyObject::CreateInstance (int id);
        PrivateCtor () {};
    };

    explicit MyObject (const PrivateCtor& pctor, int id);

private:
    
    int mID;
};

}

#endif
