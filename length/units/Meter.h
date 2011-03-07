#ifndef METER_H
#define METER_H

#include "IUnit.h"
#include "IConvertable.h"

namespace Length
{

class Meter : public IUnit, public IConvertable
{
    // The value of this Meter object
    double value;

public:
    Meter(double value);
    virtual ~Meter() { };

    // IUnit interface
    virtual double getValue();
    virtual void setValue(double value);

    // IConvertable interface
    virtual double convertTo(UnitType unit);
};

}

#endif
