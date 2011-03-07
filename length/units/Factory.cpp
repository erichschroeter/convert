#include "Factory.h"
#include "Meter.h"
#include "Inch.h"
#include "UnitNotSupportedException.h"

namespace Length
{

IUnit* Factory::CreateUnit(UnitType unit)
{
    IUnit* unitImpl;
    double defaultValue = 1.0;

    if (unit == METER)
    {
        //Meter *meter = new Meter(defaultValue);
        Meter meter(defaultValue);
        //unitImpl = new Meter(defaultValue);
        unitImpl = &meter;
    }
    else if (unit == INCH)
    {
        Inch *inch = new Inch(defaultValue);
        //unitImpl = new Inch(defaultValue);
        unitImpl = inch;
    }
    else
    {
        //throw new std::exception("The factory does not support the unit: " + unit);
        throw UnitNotSupported;
    }

    return unitImpl;
}

IConvertable* Factory::CreateConvertable(UnitType unit)
{
    IConvertable* unitImpl;
    double defaultValue = 1.0;

    if (unit == METER)
    {
        Meter *meter = new Meter(defaultValue);
        //unitImpl = new Meter(defaultValue);
        unitImpl = meter;
    }
    else if (unit == INCH)
    {
        Inch *inch = new Inch(defaultValue);
        //unitImpl = new Inch(defaultValue);
        unitImpl = inch;
    }
    else
    {
        //throw new std::exception("The factory does not support the unit: " + unit);
        throw UnitNotSupported;
    }

    return unitImpl;
}

}
