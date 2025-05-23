#include <exception>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <limits>
#include <map>

using Number = int;
typedef int Number;

class FileNotOpenedException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class FileReadError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

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

    std::map<std::string, double> fout;
    try {
        fout = parse_pairs(argv[datafile_path_index]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Опаньки! " << e.what();
        return 1;
    }
    catch (const FileNotOpenedException &e)
    {
        std::cerr << "Опаньки! " << e.what();
        return 1;
    }
    catch (const FileReadError &e)
    {
        std::cerr << "Незадачка... ";
    }

    return 0;
}
