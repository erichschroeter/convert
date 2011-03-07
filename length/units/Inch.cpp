#include "Inch.h"

namespace Length
{

Inch::Inch(double value) : value(value)
{

}

double Inch::convertTo(UnitType unit)
{
    double retValue = 0.0;

    if (unit == INCH)
    {
        retValue = value;
    }
    else if (unit == METER)
    {
    	retValue = value / 39.3700787;
    }
    else
    {
        retValue = 0.0;
    }

    return retValue;
}

double Inch::getValue()
{
    return value;
}

void Inch::setValue(double value)
{
    this->value = value;
}

}
