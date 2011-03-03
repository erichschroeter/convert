#include <iostream>
#include <boost/program_options.hpp>
#include "units/meter.h"

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
	    ("meter,m", po::value<double>(), "meters (default)")
	    ("inch,in", po::value<double>(), "inches")
	;

	po::options_description options("Allowed options");
	options.add(generic).add(config);

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, options), vm);
	po::notify(vm);

	if (vm.count("help"))
	{
	    std::cout << options << std::endl;
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

	if (vm.count("meter"))
	{
	    double meter = vm["meter"].as<double>();
	    Meter m(meter);
	    double inch = m.convertTo(INCH);
	    std::cout << inch << std::endl;
	}

	if (vm.count("inch"))
	{
	    double inch = vm["inch"].as<double>();
	    double meter = inch / 39.3700787;
	    std::cout << meter << std::endl;
	}
    }
    catch (const std::exception& e) {
	std::cout << "exception " << e.what() << std::endl;
    }

    return 0;
}
