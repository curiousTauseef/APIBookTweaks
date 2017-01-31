
#include "../../include/RedirectStdOut.h"

int main ()
{
    std::stringstream os {};
    {
        //RedirectStdOut sout {os.rdbuf() };
        RedirectStdOut sout {os};
        std::cout << "My output\n";
    }
    
    std::cout << os.str();
    
}

