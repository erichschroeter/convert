#ifndef IUNIT_H
#define IUNIT_H

namespace Length
{

/**
 * The IUnit class serves as an interface for all units of length. It contains
 * methods common amongst all Unit of length objects (i.e. Meter, Inch, etc).
 */
class IUnit
{
public:
    virtual double getValue() = 0;
    virtual void setValue(double value) = 0;
};

enum UnitType
{
    METER,
    INCH,
    LIGHT_YEAR
};

enum Multiplier
{
    milli,
    centi,
    deci,
    kilo,
    mega,
    quarter,
    eighth,
    sixteenth
};

}

#endif
