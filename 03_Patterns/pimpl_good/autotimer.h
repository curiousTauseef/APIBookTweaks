/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
///
/// \file   autotimer.h
/// \author Martin Reddy
/// \brief  An example of Pimpl with a smart pointer.
///
/// Copyright (c) 2010, Martin Reddy. All rights reserved.
/// Distributed under the X11/MIT License. See LICENSE.txt.
/// See http://APIBook.com/ for the latest version.
///

/**
 01/03/17 -- Tal

 This is essentially the impll_boost example but using c++11 unique_ptr smart ptr
 - dropped boost::scoped_ptr for std::unique_ptr
 **/

#ifndef AUTOTIMER_H
#define AUTOTIMER_H

#include <memory>
#include <string>


namespace apibook {

///
/// An object that reports how long it was alive for when it
/// is destroyed.
///
class AutoTimer
{
public:
	/// Create a new timer object with a human-readable name
	explicit AutoTimer(const std::string &name);
	/// On destruction, the timer reports how long it was alive
	~AutoTimer();

private:
    class Impl;
	std::unique_ptr<Impl> mImpl;
};

}

#endif
