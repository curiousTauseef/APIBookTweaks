/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   autotimer.cpp
/// \author Martin Reddy
/// \brief  An example of Pimpl with a smart pointer.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

/**
01/03/17 -- Tal

 - using brace-initializer
 - replaced literals with constexpr.
 - replaced new with make_unique: see Tweaks_Explained.md for reason
 - added Impl constructor that takes a string so AutoTimer ctor can take advantage of it.
 **/
#include "autotimer.h"

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

namespace apibook {

class AutoTimer::Impl
{
public:
    explicit Impl (const std::string& name) :
    mName {name}
    { }
    
    /// Return how long the object has been alive
    double GetElapsed() const
    {
#ifdef _WIN32
        constexpr auto Resolution {1e3};
        return (GetTickCount() - mStartTime) / Resolution;
#else
        constexpr auto Resolution {1e6};
        struct timeval end_time;
        gettimeofday (&end_time, NULL);
        double t1 {mStartTime.tv_usec / Resolution + mStartTime.tv_sec };
        double t2 {end_time.tv_usec / Resolution + end_time.tv_sec };
        return t2 - t1;
#endif
    }

    std::string mName;
#ifdef _WIN32
    DWORD mStartTime;
#else
    struct timeval mStartTime;
#endif
};

AutoTimer::AutoTimer(const std::string &name) :
    mImpl {std::make_unique <Impl>(name) }
{

#ifdef _WIN32
    mImpl->mStartTime = GetTickCount();
#else
    gettimeofday(&mImpl->mStartTime, NULL);
#endif
}

AutoTimer::~AutoTimer()
{
    std::cout << mImpl->mName << ": took " << mImpl->GetElapsed()
              << " secs" << std::endl;
}

}
