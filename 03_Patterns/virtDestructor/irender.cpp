/**
 irender.cpp
 
 Example of what can happen when a base class' destructor isn't virtual.
 NOTE: This example wasn't part of the APIBOOK.com example code but much of the
 code was listed in the book.  I just exapanded it a but so it would do something.
 -- 01/06/17 Tal
**/

#include <iostream>
#include <memory>

// non-virtual destructor
class IRendererNonVirtDtor
{
public:
    // example of what happens with non-virtual destructors on base classes.
    ~IRendererNonVirtDtor () {std::cout << "IRenderNonVirtDtor destructor; non-virtual\n"; }
    virtual void Render () = 0;
};

class RayTracerNonVirtDtor: public IRendererNonVirtDtor
{
public:
    RayTracerNonVirtDtor () {std::cout << "RayTracerNonVirtDtor() default constructor\n"; }
    ~RayTracerNonVirtDtor () {std::cout << "~RayTracerNonVirtDtor destructor\n"; }
    void Render () override {std::cout << "RayTracerNonVirtDtor::Render()\n"; }
};

// virtual destructor
class IRenderer
{
public:
    virtual ~IRenderer () {std::cout << "~IRender destructor; virtual\n"; }
    virtual void Render () = 0;
};

class RayTracer: public IRenderer
{
public:
    RayTracer () {std::cout << "RayTracer() default constructor\n"; }
    ~RayTracer () override {std::cout << "~RayTracer destructor\n"; }
    void Render () override {std::cout << "RayTracer::Render()\n"; }
};

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
