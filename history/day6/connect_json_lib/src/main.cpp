

#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


std::ifstream f("example.json");
json data = json::parse(f);
