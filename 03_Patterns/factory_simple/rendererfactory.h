/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   rendererfactory.h
/// \author Martin Reddy
/// \brief  A factory object to create Renderer instances.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

/**
 01/06/17 -- Tal
 - switched to an enum for specifying the factory type to build instead of strings.
 - added apibook namespace
 
 Using enum over string for factory to improve the API.
    * "A good API ... should also be difficult to misuse" -- Martin Reddy
       by doing this we are taking advantage of C++ strong type system by
       disallowing bad values.
 * For why enum class see: (https://github.com/tlanc007/APIBookTweaks/blob/master/Tweak_Explainations.md#enumclass)

 After adding the enum, it seemed appropriate to wrap the example in a namespace.
    * This would be especially true if using old-style enums as they have the issue
       of polluting the global namespace.  Although enum class doesn't pollute the global
       namespace, adding the namespace keeps the intent clear that it belongs to a
       specific code group.
    * In general, making use of namespaces is a good habit to be in with dealing with APIs.
 
 **/
 
#ifndef RENDERERFACTORY_H
#define RENDERERFACTORY_H

#include <string>

#include "renderer.h"

namespace apibook {
    

// specify the factory renderers as an enum instead of a string
enum class RendererType {
    opengl,
    directx,
    mesa
};

///
/// A factory object that creates instances of different
/// 3D renderers.
///
class RendererFactory
{
public:
    /// Create a new instance of a named 3D renderer.
    /// type can be one of opengl, directx, or mesa
    IRenderer *CreateRenderer(const RendererType &type);
};

} // apibook namespace

#endif
