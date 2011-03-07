#include "Meter.h"

namespace Length
{

Meter::Meter(double value) : value(value)
{

}

double Meter::convertTo(UnitType unit)
{
    double retValue = 0.0;

    if (unit == METER)
    {
        retValue = value;
    }
    else if (unit == INCH)
    {
    	retValue = value * 39.3700787;
    }
    else
    {
        retValue = 0.0;
    }

    return retValue;
}

double Meter::getValue()
{
    return value;
}

void Meter::setValue(double value)
{
    this->value = value;
}

}
