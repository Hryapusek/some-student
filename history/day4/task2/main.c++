#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <map>

int main(int argc, const char** argv)
{
    constexpr int incorrect_parameters_exit_code = 1;
    constexpr int filename_index = 0;
    constexpr int datafile_path_index = 1;

    if(argc < 1)
    {
        std::cerr << "Program usage: " << argv[filename_index] << " <path to file with data>" << std::endl;
        return incorrect_parameters_exit_code;
    }

    std::ifstream ifile{argv[datafile_path_index]};
    if (not ifile.is_open())
    {
        return incorrect_parameters_exit_code;
    }

    std::string key;

    while ((! ifile.eof()) && (! ifile.bad()))
    {
        std::getline(ifile, key, ':');
        if (ifile.fail())
        {
            std::cerr << "Key incorrect" << std::endl;
            ifile.clear();
            ifile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        double param;
        ifile >> param;
        if (ifile.fail())
        {
            std::cerr << "Parameter incorrect" << std::endl;
            ifile.clear();
            ifile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    } 
}


std::map<std::string, double> parse_pairs(const std::string& filepath)
{

    std::ifstream ifile{argv[datafile_path_index]};
    if (not ifile.is_open())
    {
        return incorrect_parameters_exit_code;
    }

    
}
