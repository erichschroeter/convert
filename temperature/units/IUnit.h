#ifndef IUNIT_H
#define IUNIT_H

namespace Temperature
{

/**
 * The IUnit class serves as an interface for all units of temperature. It contains
 * methods common amongst all Unit of temperature objects (i.e. Celsius, Fahrenheit, etc).
 */
class IUnit
{
public:
    virtual double getValue() = 0;
    virtual void setValue(double value) = 0;
};

enum UnitType
{
    CELSIUS,
    FAHRENHEIT
};

}

#endif
