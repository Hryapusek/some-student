// char * -> "amogus"
// char ** -> char*, char*, char*

#include <vector>
#include <iostream>
#include <types/program_level.h>
#include <json/program_level_parcer_json.h>

int main(int argc, char** argv)
{
    // argc - количество (1, 2)
    if (argc < 2)
    {        
        std::cout << "Usage of " << argv[0] << ": " << argv[0] << " <path to json-file> \n";
        return 1;
    }

    std::vector<cjl::ProgramLevel> list_of_programms;
    try {
        list_of_programms = cjl::json::program_level_parser_json(argv[1]);
    }
    catch (std::exception& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
        return 1;
    }

    for (cjl::ProgramLevel p : list_of_programms)
    {
        std::cout << "Pair: " << p << '\n';
    }

    return 0;
}
