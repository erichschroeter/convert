#include "Fahrenheit.h"
#include "UnitNotSupportedException.h"

namespace Temperature
{

Fahrenheit::Fahrenheit(double value) : value(value)
{

}

double Fahrenheit::convertTo(UnitType unit)
{
    double retValue = 0.0;

    if (unit == FAHRENHEIT)
    {
        retValue = value;
    }
    else if (unit == CELSIUS)
    {
    	retValue = ((value - 32.0) * 5.0) / 9.0;
    }
    else
    {
        throw UnitNotSupportedException();
    }

    return retValue;
}

double Fahrenheit::getValue()
{
    return value;
}

void Fahrenheit::setValue(double value)
{
    this->value = value;
}

}
