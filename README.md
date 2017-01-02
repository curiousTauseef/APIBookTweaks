# APIBookTweaks
Tweaks to examples from  API Design for C++ book.

[![Build Status](https://travis-ci.org/tlanc007/APIBookTweaks.svg?branch=tests)](https://travis-ci.org/tlanc007/APIBookTweaks)

Tal Lancaster  
Orig Dec 30, 2016  
Last updated: Jan 02, 2016

## Table of Contents

<a href="#background">Background</a><br>
<a href="#status">Status</a><br>
<a href="#building">Building</a><br>
<a href="#travis">Integration/Testing</a><br>

<a class="anchor" href="#background"></a>
## Background
The following are certain examples from Martin Reddy's *API Design For C++* book.  The all of the original examples from the book can be found at: [http://APIBook.com]().

For the most, part there isn't anything technically wrong with the examples, that are tweaked.  It is that I prefer to see the examples make better use of modern C++ (C++11/C++14).  Also when possible removed external dependencies on other libraries where pure C++ could handle the example just fine.

The markdown file [Tweak Explanations](https://github.com/tlanc007/APIBookTweaks/tree/master/Tweak_Explainations) gives some explanation of the various tweaks performed.

Only certain examples from the book have been tweaked and are here.  For example, I didn't bother adding a tweaked version, if the only change that stood out to me was switching to _brace-init-list_ form (`int i {2}`).

The expectation is that one would have both versions of the example handy and use some utility that compares files.

<a class="anchor" href="#background"></a>
## Status
Currently the tweaked examples are only from chapter 2.

I am still reading the book and will be adding examples as I come across them.

<a class="anchor" href="#building"></a>
## Building
The original examples for [API Design for C++](http://APIBook.com) are prepared nicely and are set up to build under _cmake_.  These tweaked examples also are set up to be built under _cmake_.

A way to keep the examples and the build files separate is to create a directory, say "build" and run the configure script from within that directory.

```
mkdir build
cd build
cmake ..
```

Assuming you started in the top directory APIBookTweaks directory.  This should configure the entire project for use with Makefile.

or to be explicit for configuring for Makefiles, the last command can be:

```
cmake -G “Unix Makefiles” ..
```

If you happening to be running under OSX (or macOS as it is now called) and want to build the project to be used under Xcode, one can use:

```
cmake -G “Xcode” ..
```

<a class="anchor" href="#travis"></a>
## Integration and Testing
This project is making use of travis for integrating and [catch](https://github.com/philsquared/Catch) for testing. Typically, [Google Test](https://github.com/google/googletest) is my goto setup for testing and mocking.  But I wanted to minimize the dependencies for this project.  Note, the testing and integration only occurs on the *tests* branch.

As the project is using _cmake_, I could have used _ctest_ and captured stdout.  Honestly, it would have been the been the most direct solution considering that the examples are just a set of standalone programs.  But it seemed a bit old fashioned, and this gave me an opportunity to try another test library.
