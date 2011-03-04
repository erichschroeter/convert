#ifndef METER_H
#define METER_H

#include "Units.h"

class Meter
{
    // The value of this Meter object
    double value;

public:
    Meter(double value);

    double convertTo(UnitType unit);
};

#endif
