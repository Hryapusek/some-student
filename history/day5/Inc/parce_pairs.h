
/**
@brief 
 */

#include <string>
#include <map>
#include <stdexcept>

namespace parser
{
    class FileNotOpenedException : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };
    
    class FileReadError : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };

    std::map<std::string, double> parse_pairs(const std::string& filepath);
}
