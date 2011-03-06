#ifndef METER_H
#define METER_H

#include "Units.h"
#include "ILengthConvertable.h"

namespace Length
{

class Meter : public ILengthConvertable
{
    // The value of this Meter object
    double value;

public:
    Meter(double value);

    // ILengthConvertable interface
    virtual double convertTo(UnitType unit);
};

}

#endif
