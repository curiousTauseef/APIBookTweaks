#include <sstream>

#include "RedirectStdOut.h"
#include "rendererfactory.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using std::cout;
constexpr char NL {'\n'};

/// An OpenGL-based 3D renderer
class OpenGLRenderer : public IRenderer
{
public:
    ~OpenGLRenderer() {}
    bool LoadScene(const std::string &filename) { return true; }
    void SetViewportSize(int w, int h) {}
    void SetCameraPos(double x, double y, double z) {}
    void SetLookAt(double x, double y, double z) {}
    void Render () { cout << "OpenGL Render" << NL; }
    static RendererFactory::UniqueIRendererPtr Create () { return std::make_unique <OpenGLRenderer> (); }
};

/// A DirectX-based 3D renderer
class DirectXRenderer : public IRenderer
{
public:
    bool LoadScene(const std::string &filename) { return true; }
    void SetViewportSize(int w, int h) {}
    void SetCameraPos(double x, double y, double z) {}
    void SetLookAt(double x, double y, double z) {}
    void Render () { cout << "DirectX Render" << NL; }
    static RendererFactory::UniqueIRendererPtr Create () { return std::make_unique <DirectXRenderer> (); }
};

/// A Mesa-based software 3D renderer
class MesaRenderer : public IRenderer
{
public:
    bool LoadScene(const std::string &filename) { return true; }
    void SetViewportSize(int w, int h) {}
    void SetCameraPos(double x, double y, double z) {}
    void SetLookAt(double x, double y, double z) {}
    void Render() { cout << "Mesa Render" << NL; }
    static RendererFactory::UniqueIRendererPtr Create () { return std::make_unique <MesaRenderer> (); }
};

TEST_CASE ("03 factoryExtensibleTest", "[factory_extensible]")
{
    const std::string capturedOutput {
R"(OpenGL Render
Mesa Render
Mesa renderer unregistered
)"
    };
    
    std::stringstream os {};
    {
        RedirectStdOut rdOut {os};
        {
            // register the various 3D renderers with the factory object
            RendererFactory::RegisterRenderer ("opengl", OpenGLRenderer::Create);
            RendererFactory::RegisterRenderer ("directx", DirectXRenderer::Create);
            RendererFactory::RegisterRenderer ("mesa", MesaRenderer::Create);
            
            // create an OpenGL renderer
            RendererFactory::UniqueIRendererPtr ogl {RendererFactory::CreateRenderer("opengl") };
            ogl->Render();

            // create a Mesa software renderer
            RendererFactory::UniqueIRendererPtr mesa {RendererFactory::CreateRenderer("mesa") };
            mesa->Render();

            // unregister the Mesa renderer
            RendererFactory::UnregisterRenderer("mesa");
            mesa = RendererFactory::CreateRenderer("mesa");
            if (! mesa)
            {
                cout << "Mesa renderer unregistered" << NL;
            }
        }
    }
    CHECK (capturedOutput == os.str () );
}
