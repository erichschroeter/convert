#ifndef ICONVERTABLE_H
#define ICONVERTABLE_H

#include "IUnit.h"

namespace Temperature
{

class IConvertable
{
public:
    virtual double convertTo(UnitType unit) = 0;
};

}

#endif
