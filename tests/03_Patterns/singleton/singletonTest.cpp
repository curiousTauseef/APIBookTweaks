#include <sstream>

#include "singleton.h"

/**
 1/5/17 -- Tal
 using ctest directly
 can't use TEST to redirect output as the last std:out doesn't occur
 until after main shutsdown.
 **/

#include "singleton.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int, char **)
{
    cout << "main() called" << endl;
    
    // singleton gets created here
    Singleton &foo {Singleton::GetInstance () };
    foo.GetState();
    
    // returns previously allocated singleton here
    Singleton &foo2 { Singleton::GetInstance() };
    foo2.GetState();
    
    return 0;
}
