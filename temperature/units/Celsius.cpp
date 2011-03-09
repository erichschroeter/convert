#include "Celsius.h"
#include "UnitNotSupportedException.h"

namespace Temperature
{

Celsius::Celsius(double value) : value(value)
{

}

double Celsius::convertTo(UnitType unit)
{
    double retValue = 0.0;

    if (unit == CELSIUS)
    {
        retValue = value;
    }
    else if (unit == FAHRENHEIT)
    {
    	retValue = (9.0 / 5.0) * value + 32.0;
    }
    else
    {
        throw UnitNotSupportedException();
    }

    return retValue;
}

double Celsius::getValue()
{
    return value;
}

void Celsius::setValue(double value)
{
    this->value = value;
}

}
