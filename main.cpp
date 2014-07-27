#include <iostream>
#include <string>
#include <concurrentqueue.h>
#include "boost/program_options.hpp"

using namespace std;
namespace po = boost::program_options;

int main(int argc, char** argv)
{
    uint32_t crawlerLvl = 0;

    // Declare the supported options.
    boost::program_options::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("level,l", po::value<uint32_t>(&crawlerLvl)->default_value(10), "set crawler level")
        ("source,s", po::value<std::string>(), "set crawler start url")
    ;

    po::positional_options_description p;
    p.add("source", -1);

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::store(po::command_line_parser(argc, argv).
              options(desc).positional(p).run(), vm);
    po::notify(vm);


    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }

    if (vm.count("level")) {
        cout << "Crawler level was set to "
     << vm["level"].as<uint32_t>() << ".\n";
    } else {
        cout << "Crawler level was not set\n";
    }

    if (vm.count("source")) {
        cout << "Crawler level was set to "
     << vm["source"].as<std::string>() << ".\n";
    } else {
        cout << "Source was not set.\n";
    }

    cout << "Hello World!" << endl;
    return 0;
}

