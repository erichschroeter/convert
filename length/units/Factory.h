#ifndef FACTORY_H
#define FACTORY_H

#include "IUnit.h"
#include "IConvertable.h"

namespace Length
{

/**
 * The UnitFactory is an implementation of the Factory Pattern. It is responsible for
 * creating Unit of length objects (i.e. IUnit).
 */
class Factory
{
public:
    static IUnit* CreateUnit(UnitType unit);
    static IConvertable* CreateConvertable(UnitType unit);
};

}

#endif
