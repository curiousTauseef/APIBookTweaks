/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   renderer.h
/// \author Martin Reddy
/// \brief  An abstract base class for a simple 3D renderer.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

/**
 01/07/17 -- Tal
 - added apibook namespace
     * See comment in source renderfactory.h for reasoning for it.
 **/

#ifndef RENDERER_H
#define RENDERER_H

#include <string>

namespace apibook {

///
/// An abstract interface for a 3D renderer.
///
class IRenderer
{
public:
    virtual ~IRenderer() {}
    virtual bool LoadScene(const std::string &filename) = 0;
    virtual void SetViewportSize(int w, int h) = 0;
    virtual void SetCameraPos(double x, double y, double z) = 0;
    virtual void SetLookAt(double x, double y, double z) = 0;
    virtual void Render() = 0;
};

} // apibook namespace

#endif
