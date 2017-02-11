/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  A simple example of a Factory Method.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

/**
 01/06/17 -- tal
 - switched unique_ptrs so don't have to manually delete
 * refer to: (https://github.com/tlanc007/APIBookTweaks/blob/master/Tweak_Explainations.md#smartpointers)
 - using enum rather than string to specify factory class
 * refer to: (https://github.com/tlanc007/APIBookTweaks/blob/master/Tweak_Explainations.md#enumclass)
 - need to qualify with namespace apibook
 **/

#include <memory>

#include "rendererfactory.h"

int main(int, char **)
{
    // create the factory object
    std::unique_ptr<apibook::RendererFactory> f {std::make_unique<apibook::RendererFactory> () };

    // create an OpenGL renderer
    std::unique_ptr<apibook::IRenderer> ogl {};
    ogl.reset (f->CreateRenderer(apibook::RendererType::opengl) );
    ogl->Render();

    // create a Mesa software renderer
    std::unique_ptr<apibook::IRenderer> mesa {};
    mesa.reset (f->CreateRenderer(apibook::RendererType::mesa) );
    mesa->Render();

}
