#include <iostream>
#include <boost/program_options.hpp>
#include "units/Meter.h"
#include "units/Inch.h"

namespace po = boost::program_options;

bool verbose = false;

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
            ("from-unit", po::value<std::string>(), "The unit of length to convert from")
            ("to-unit", po::value<std::vector< std::string> >(), "The unit(s) of length to convert to")
        ;
        // make the VALUE, TO, and FROM options positional
        // allow user to specify multiple conversions
        // if none are specified, default will return the same unit as the FROM option
        po::positional_options_description input;
        input.add("value", 1).add("from-unit", 1).add("to-unit", -1);
	/*config.add_options()
            ("multiplier,x", po::value<std::string>(), "multiplier (e.g. cm, mm, quarter, etc.)")
	    ("meter,m", po::value<double>(), "meters (default)")
	    ("inch,i", po::value<double>(), "inches")
            ("light-year,L", po::value<double>(), "light years")
	;*/

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
        
        std::vector<std::string> convertTo = vm["to-unit"].as< std::vector<std::string> >();

        for (int i=0; i < convertTo.size(); i++)
        {
            std::cout << convertTo[i] << std::endl;
        }
/*
	if (vm.count("meter"))
	{
	    double meters = vm["meter"].as<double>();
	    Meter meter(meters);
	    double inch = meter.convertTo(INCH);
	    std::cout << inch << std::endl;
	}

	if (vm.count("inch"))
	{
	    double inches = vm["inch"].as<double>();
	    //double meter = inch / 39.3700787;
            Inch inch(inches);
            double meter = inch.convertTo(METER);
	    std::cout << meter << std::endl;
	}*/
    }
    catch (const std::exception& e) {
	std::cout << "exception " << e.what() << std::endl;
    }

    return 0;
}
