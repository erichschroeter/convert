#include <iostream>
#include <boost/foreach.hpp>
#include <boost/program_options.hpp>
#include "units/IUnit.h"
#include "units/Celsius.h"
#include "units/Fahrenheit.h"
#include "units/Factory.h"

namespace po = boost::program_options;

bool verbose = false;

/**
 * This is an overloaded operator>> function to help validate units
 * passed from the command line.
 */
std::istream& operator>>(std::istream& in, Temperature::UnitType& unit)
{
    std::string token;
    in >> token;
    if (token == "fahrenheit")
    {
        unit = Temperature::FAHRENHEIT;
    }
    else if (token == "f")
    {
        unit = Temperature::FAHRENHEIT;
    }
    else if (token == "celsius")
    {
        unit = Temperature::CELSIUS;
    }
    else if (token == "c")
    {
        unit = Temperature::CELSIUS;
    }
    else
    {
        throw po::validation_error("No unit matches " + token);
    }

    return in;
}

int main (int argc, char *argv[])
{
    try
    {
	// These are generic options common to most applications
	po::options_description generic("Generic options");
	generic.add_options()
	    ("help,h", "displays this help message")
	    ("version,v", "displays the version")
	    ("verbose", "shows more in-depth information about what the program is doing")
	;

	// These are the options pertinent to this application
	po::options_description config("Configuration");
        config.add_options()
            ("value", po::value<double>(), "The value to convert from")
            ("from", po::value<Temperature::UnitType>(), "The unit of temperature to convert from")
            ("to", po::value< std::vector<Temperature::UnitType> >()->multitoken(), "The unit(s) of temperature to convert to")
        ;
        // make the VALUE, TO, and FROM options positional
        // allow user to specify multiple conversions
        // if none are specified, default will return the same unit as the FROM option
        po::positional_options_description input;
        input.add("value", 1).add("from", 1).add("to", -1);
	
	po::options_description allowed_options("Allowed options");
	allowed_options.add(generic).add(config);

	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).options(allowed_options).positional(input).run(), vm);
	po::notify(vm);

	if (vm.count("help"))
	{
	    std::cout << allowed_options << std::endl;
	    return 0;
	}

	if (vm.count("version"))
	{
	    std::cout << "0.1" << std::endl;
	}

	if (vm.count("verbose"))
	{
	    verbose = true;
	}

        double value = vm["value"].as<double>();
        Temperature::UnitType from = vm["from"].as<Temperature::UnitType>();
        
        // use Factory to create unit of temperature
        Temperature::IConvertable* convertable = Temperature::Factory::CreateConvertable(from);

        // convert to all the other given units
        BOOST_FOREACH(Temperature::UnitType unit, vm["to"].as< std::vector<Temperature::UnitType> >())
        {
            double conversion = convertable->convertTo(unit);
            std::cout << conversion << " " << unit << std::endl;
        }
    }
    catch (const std::exception& e) {
	std::cout << "exception " << e.what() << std::endl;
    }

    return 0;
}
