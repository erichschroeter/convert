#ifndef UNITNOTSUPPORTEDEXCEPTION_H
#define UNITNOTSUPPORTEDEXCEPTION_H

#include <exception>

class UnitNotSupportedException : public std::exception
{
    virtual const char* what() const throw()
    {   
        return "Unit not supported";
    }   
};

#endif
