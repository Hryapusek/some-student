#include <iostream>
#include <fstream>
#include <limits>
#include <parce_pairs.h>

namespace parser
{

std::map<std::string, double> parse_pairs(const std::string& filepath)
{
    std::ifstream ifile{filepath};
    if (not ifile.is_open())
    {
        throw FileNotOpenedException("Файл с именем ... не удалось открыть ");
    }

    std::map<std::string, double> fout;
    
    while ((! ifile.eof()) && (! ifile.bad()))
    {
        std::string key;
        std::getline(ifile, key, ':');
        if (ifile.fail())
        {
            std::cerr << "Key incorrect" << std::endl;
            ifile.clear(ifile.rdstate() & (~std::ios::failbit));
            ifile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        double param;
        ifile >> param;
        if (ifile.fail())
        {
            std::cerr << "Parameter incorrect" << std::endl;
            ifile.clear(ifile.rdstate() & (~std::ios::failbit));
            ifile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        // fout.insert(std::pair<std::string, double>(key, param));
        fout.insert({key, param});
    }

    if (ifile.bad())
    {
        throw FileReadError("");
    }
    return fout;
}
}
