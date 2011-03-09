#ifndef ICONVERTABLE_H
#define ICONVERTABLE_H

#include <string>
#include "IUnit.h"

namespace Length
{

class IConvertable
{
public:
    virtual double convertTo(UnitType unit) = 0;
    virtual std::string as(UnitType unit) = 0;
};

}

#endif
