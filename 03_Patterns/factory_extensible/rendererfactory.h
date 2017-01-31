/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   rendererfactory.h
/// \author Martin Reddy
/// \brief  A factory object to create IRenderer instances.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

/**
 1/30/17 -- Tal
 -- switched to using alias from typedef
    for CreateCallback and CallbackMap
 -- using unordered_map instead of map
   insertions can be faster as sorting isn't important.
 -- switched to unique_ptr/make_unique rather than needing to
   use new() and remembering to call delete.
 
 **/

#ifndef RENDERERFACTORY_H
#define RENDERERFACTORY_H

#include <string>
#include <memory>
#include <unordered_map>

#include "renderer.h"

///
/// A factory object that creates instances of different
/// 3D renderers. New renderers can be dynamically added
/// and removed from the factory object.
///
class RendererFactory
{
public:
    /// The type for the callback that creates an IRenderer instance
    using UniqueIRendererPtr = std::unique_ptr <IRenderer>;
    using CreateCallback = UniqueIRendererPtr (*) ();
    
    /// Add a new 3D renderer to the system
    static void RegisterRenderer(const std::string &type,
                                 CreateCallback cb);
    /// Remove an existing 3D renderer from the system
    static void UnregisterRenderer(const std::string &type);

    /// Create an instance of a named 3D renderer
    static UniqueIRendererPtr CreateRenderer(const std::string &type);

private:
    using CallbackMap = std::unordered_map <std::string, CreateCallback>;
    static CallbackMap mRenderers;
};

#endif
