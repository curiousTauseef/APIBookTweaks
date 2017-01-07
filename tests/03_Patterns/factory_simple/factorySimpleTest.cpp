

#include <memory>
#include <sstream>

#include "RedirectStdOut.h"
#include "rendererfactory.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE ("03 factorySimpleTest", "[factory_simple]")
{
    const std::string capturedOutput {
R"(OpenGL Render
Mesa Render
)"
    };
    
    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};
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
    }
    
    CHECK (capturedOutput == os.str () );
}


