#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H

#include "IUnit.h"
#include "IConvertable.h"

namespace Temperature
{

class Fahrenheit : public IUnit, public IConvertable
{
    // The value of this Fahrenheit object
    double value;

public:
    Fahrenheit(double value);
    virtual ~Fahrenheit() { };

    // IUnit interface
    virtual double getValue();
    virtual void setValue(double value);

    // IConvertable interface
    virtual double convertTo(UnitType unit);
};

}

#endif
