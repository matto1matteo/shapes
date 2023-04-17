#include <iostream>
#include <shapes/shapes.h>

int main (int argc, char *argv[])
{
    #ifdef BUILD_TEST
    std::cout << "Hello maaaan" << std::endl;
    
    #endif // DEBUG
    
    std::cout << Greet("Matteo") << std::endl;
    return 0;
}
