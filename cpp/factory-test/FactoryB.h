#include "Factory.h"

class FactoryB : public Factory
{
private:
    /* data */
public:
    FactoryB(/* args */);
    ~FactoryB();
    static FactoryB o_Factory;

    int CreateEOD() override;
};

