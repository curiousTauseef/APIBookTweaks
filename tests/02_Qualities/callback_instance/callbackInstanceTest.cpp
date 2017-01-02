#include <sstream>

#include "RedirectStdOut.h"
#include "modulea.h"
#include "moduleb.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE ("02 callbackInstance", "[callbackInstance") {
    const std::string captureOutput {"In instance callback: 'Hello World' (closure=42)\n"};
    
    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};
        
        apibook::ModuleB b {};
        apibook::ModuleA a {};
        int closure {42};
        
        // add a callback for ModuleA to ModuleB
        b.SetCallback (&a, apibook::ModuleA::StaticWrapper, &closure);
        // tell ModuleB to invoke all its callbacks
        b.DoAction ();
    }
    
    CHECK (captureOutput == os.str() );
}

