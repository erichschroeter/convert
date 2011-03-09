#ifndef CELSIUS_H
#define CELSIUS_H

#include "IUnit.h"
#include "IConvertable.h"

namespace Temperature
{

class Celsius : public IUnit, public IConvertable
{
    // The value of this Celsius object
    double value;

public:
    Celsius(double value);
    virtual ~Celsius() { };

    // IUnit interface
    virtual double getValue();
    virtual void setValue(double value);

    // IConvertable interface
    virtual double convertTo(UnitType unit);
};

}

#endif
