#ifndef UNITS_H
#define UNITS_H

namespace Length
{

enum UnitType
{
    METER,
    INCH
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
/*
std::string Units = {
    "inch",
    "in",
    "meter",
    "m",
    "centimeter",
    "millimeter",
    "kilometer",
    "decimeter"
};
*/
}

#endif
