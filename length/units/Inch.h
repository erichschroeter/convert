#ifndef INCH_H
#define INCH_H

#include "Units.h"

class Inch
{
    // The value of this Inch object
    double value;

public:
    Inch(double value);

    double convertTo(UnitType unit);
};

#endif
