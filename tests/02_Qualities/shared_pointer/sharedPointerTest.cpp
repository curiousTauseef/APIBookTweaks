#include <sstream>

#include "RedirectStdOut.h"
#include "myobject.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE ("02 SharedPointer", "[sharedPointer]") {
    const std::string capturedOutput {
R"(> main()
> CreateInstance(1)
... created object (with key)1
> CreateInstance(2)
... created object (with key)2
... destroyed object 1
... destroyed object 2
> exit()
)"
    };
    
    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};

        std::cout << "> main()\n";
        {
            apibook::MyObjectPtr ptr;
            
            // create a new instance of MyObject
            std::cout << "> CreateInstance(1)" << "\n";
            ptr = apibook::MyObject::CreateInstance(1);
            
            // create another instance of MyObject
            std::cout << "> CreateInstance(2)" << "\n";
            ptr = apibook::MyObject::CreateInstance(2);
        }
        std::cout << "> exit()\n";
        }

    std::string result {os.str() };
    
    CHECK (capturedOutput == result);
}



