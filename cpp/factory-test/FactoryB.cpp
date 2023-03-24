#include "FactoryB.h"
#include <iostream>


FactoryB FactoryB::o_Factory;

FactoryB::FactoryB(/* args */)
{
    std::cout << "Child" << std::endl;
    gp_Factory = &o_Factory;
}

FactoryB::~FactoryB()
{
}

int FactoryB::CreateEOD()
{
    return 20;
}