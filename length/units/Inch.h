#ifndef INCH_H
#define INCH_H

#include <string>
#include "IUnit.h"
#include "IConvertable.h"

namespace Length
{

class Inch : public IUnit, public IConvertable
{
    // The value of this Inch object
    double value;

public:
    Inch(double value);
    virtual ~Inch() { };

    // IUnit interface
    virtual double getValue();
    virtual void setValue(double value);

    // IConvertable interface
    virtual double convertTo(UnitType unit);
    virtual std::string as(UnitType unit);
};

}

#endif
