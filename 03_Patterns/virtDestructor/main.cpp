#include "irender.h"

int main ()
{
    {
        std::cout << "Non-virtual dtor example\n";
        std::unique_ptr<IRendererNonVirtDtor> r1 {std::make_unique <RayTracerNonVirtDtor> () };
    }
    {
        std::cout << "\nVirtual dtor example\n";
        std::unique_ptr<IRenderer> r2 {std::make_unique <RayTracer> () };
    }
}
