#pragma once

#include <vector>
#include <types/program_level.h>


namespace cjl::json // c++17
{
    std::vector<cjl::ProgramLevel> program_level_parser_json(const std::string& file_path);
}
