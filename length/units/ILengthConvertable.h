#ifndef ILENGTHCONVERTABLE_H
#define ILENGTHCONVERTABLE_H

#include "Units.h"

namespace Length
{

class ILengthConvertable
{
public:
    virtual double convertTo(UnitType unit) = 0;
};

}

#endif
