#include <sstream>
#include "Inch.h"
#include "UnitNotSupportedException.h"

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
        throw UnitNotSupportedException();
    }

    return retValue;
}

std::string Inch::as(UnitType unit)
{
    std::string unitStr;

    if (unit == INCH)
    {
        unitStr = " inches";
    }
    else if (unit == METER)
    {
    	unitStr = " meters";
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

double Inch::getValue()
{
    return value;
}

void Inch::setValue(double value)
{
    this->value = value;
}

}
