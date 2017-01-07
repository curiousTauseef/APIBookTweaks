#include <sstream>

#include "RedirectStdOut.h"
#include "irender.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE ("03 virtDestructorTest", "[virtDtor]") {
    const std::string capturedOutput {
R"(Non-virtual dtor example
RayTracerNonVirtDtor() default constructor
IRenderNonVirtDtor destructor; non-virtual

Virtual dtor example
RayTracer() default constructor
~RayTracer destructor
~IRender destructor; virtual
)"
    };
    
    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};
        {
            std::cout << "Non-virtual dtor example\n";
            std::unique_ptr<IRendererNonVirtDtor> r1 {std::make_unique <RayTracerNonVirtDtor> () };
        }
        {
            std::cout << "\nVirtual dtor example\n";
            std::unique_ptr<IRenderer> r2 {std::make_unique <RayTracer> () };
        }
    }
    
    CHECK (capturedOutput == os.str () );
}

