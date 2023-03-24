// #define FACTORY_EXTENDED
#define MY_MACRO 43
#include "Factory.h"
#include <iostream>

int main()
{

    if (gp_Factory != nullptr)
    {
        std::cout << gp_Factory->CreateEOD() << std::endl;
    }
    else
    {
        std::cout << "GP is null" << std::endl;
    }

    std::cout << "MY_MACRO = " << MY_MACRO << std::endl;
    return 0;
}