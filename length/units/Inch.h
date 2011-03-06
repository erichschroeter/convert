#ifndef INCH_H
#define INCH_H

#include "Units.h"
#include "ILengthConvertable.h"

namespace Length
{

class Inch : public ILengthConvertable
{
    // The value of this Inch object
    double value;

public:
    Inch(double value);

    // ILengthConvertable interface
    virtual double convertTo(UnitType unit);
};

}

#endif
