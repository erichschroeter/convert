#include "Inch.h"

Inch::Inch(double value) : value(value)
{

}

double Inch::convertTo(UnitType unit)
{
    double retValue = 0.0;

    if (unit == METER)
    {
    	retValue = value / 39.3700787;
    }
    else
    {
        retValue = 0.0;
    }

    return retValue;
}

