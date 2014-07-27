#include <iostream>
#include <concurrentqueue.h>
#include "boost/program_options.hpp"

using namespace std;
namespace po = boost::program_options;

int main(int argc, char** argv)
{
    // Declare the supported options.
    boost::program_options::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("level", po::value<int>(), "set crawler level")
        ("source", po::value<int>(), "set crawler start url")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }

    if (vm.count("compression")) {
        cout << "Compression level was set to "
     << vm["compression"].as<int>() << ".\n";
    } else {
        cout << "Compression level was not set.\n";
    }

    cout << "Hello World!" << endl;
    return 0;
}

