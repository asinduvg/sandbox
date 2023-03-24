#include "Factory.h"
#include <iostream>
// #undef FACTORY_NOT_EXTENDED

Factory* gp_Factory = nullptr;

Factory Factory::o_Factory;

Factory::Factory()
{
    std::cout << "Parent" << std::endl;
    if (gp_Factory == nullptr)
    {
        std::cout << "hi" << std::endl;
        gp_Factory = &o_Factory;
    }
}

Factory::~Factory()
{

}
