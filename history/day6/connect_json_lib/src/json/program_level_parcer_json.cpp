
#include <json/program_level_parcer_json.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace cjl::json
{
using json = nlohmann::json;


    std::vector<cjl::ProgramLevel> program_level_parser_json(const std::string& file_path)
    {
        std::ifstream f(file_path);
        if (not f.is_open())
        {
            throw std::invalid_argument("Failed to open " + file_path); // уточнить, почему не нужен std::endl
        }
        
        std::cout << "Going to parse\n";
        json data = json::parse(f);
        std::cout << "Parse success\n";
        
        std::vector<cjl::ProgramLevel> list_of_program;
        // data["programs"].get<json::array_t>() = [ json, json, json ]
        // val -> json
        for (const json& val : data["programms"].get<json::array_t>())
        {
          cjl::ProgramLevel one_program (val["program"].get<json::string_t>(), val["level"].get<json::number_unsigned_t>());
          std::cout << "Added one more pair\n";
          list_of_program.push_back(one_program);
          std::cout << "Added one more pair to the list\n";
        }

        return list_of_program;
    }
}