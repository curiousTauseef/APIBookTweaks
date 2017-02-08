/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   main.cpp
/// \author Martin Reddy
/// \brief  An example of the Adapter design pattern.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

#include <sstream>

#include "RedirectStdOut.h"
#include "adapter.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE ("03 adapterTest", "[adapter]")
{
    const std::string capturedOutput {
R"(Allocated new Original object inside Adapter
About to call Original::DoOperation from Adapter::DoSomething
In Original::DoSomething with value 42 and flag 1
Destroyed Original object inside Adapter
)"
    };
    
    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};
        {
            // create an adapter object and call one of its functions
            Adapter adapter;
            adapter.DoSomething(42);
        }
    }
    
    CHECK (capturedOutput == os.str () );
}
