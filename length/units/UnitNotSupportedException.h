#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class UnitNotSupportedException : public std::exception
{
    virtual const char* what() const throw()
    {   
        return "Unit not supported";
    }   
} UnitNotSupported;

#endif
