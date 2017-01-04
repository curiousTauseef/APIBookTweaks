#include <sstream>

#include "RedirectStdOut.h"
#include "autotimer.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

bool matchSubStr (const std::string& strSrc, const std::string& substr)
{
    return strSrc.find (substr) != std::string::npos;
}

TEST_CASE ("03 PimplGoodTest", "[pimplGood]") {
    const std::string capturedOutput {
R"(.....
MyTimer: took )"
    };
    
    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};
        {
            apibook::AutoTimer timer {"MyTimer"};
            for (int i {0}; i < 1000; ++i)
            {
                std::cout << ".";
            }
            std::cout << "\n";
        }
    }

    std::string result {os.str() };
    
    // As the timing will be different between runs only checking for part of the string
    CHECK (matchSubStr (result, capturedOutput) );
}



