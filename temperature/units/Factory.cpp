#include "Factory.h"
#include "Celsius.h"
#include "Fahrenheit.h"
#include "UnitNotSupportedException.h"

namespace Temperature
{

IUnit* Factory::CreateUnit(UnitType unit)
{
    IUnit* unitImpl;
    double defaultValue = 1.0;

    if (unit == CELSIUS)
    {
        Celsius *celsius = new Celsius(defaultValue);
        unitImpl = celsius;
    }
    else if (unit == FAHRENHEIT)
    {
        Fahrenheit *fahrenheit = new Fahrenheit(defaultValue);
        unitImpl = fahrenheit;
    }
    else
    {
        throw UnitNotSupportedException();
    }

    return unitImpl;
}

IConvertable* Factory::CreateConvertable(UnitType unit)
{
    IConvertable* unitImpl;
    double defaultValue = 1.0;

    if (unit == CELSIUS)
    {
        Celsius *celsius = new Celsius(defaultValue);
        unitImpl = celsius;
    }
    else if (unit == FAHRENHEIT)
    {
        Fahrenheit *fahrenheit = new Fahrenheit(defaultValue);
        unitImpl = fahrenheit;
    }
    else
    {
        throw UnitNotSupportedException();
    }

    return unitImpl;
}

}
