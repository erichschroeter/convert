#include <sstream>
#include "Meter.h"
#include "UnitNotSupportedException.h"

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
        throw UnitNotSupportedException();
    }

    return retValue;
}

std::string Meter::as(UnitType unit)
{
    std::string unitStr;

    if (unit == METER)
    {
        unitStr = " meters";
    }
    else if (unit == INCH)
    {
    	unitStr = " inches";
    }
    else
    {
        throw UnitNotSupportedException();
    }

    std::stringstream concatStr;
    concatStr << convertTo(unit) << unitStr;
    unitStr = concatStr.str();

    return unitStr;

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
